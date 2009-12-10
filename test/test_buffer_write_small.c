#include <bert/buffer.h>

#include "test.h"
#include <string.h>

#define DATA_SIZE	4

int main()
{
	unsigned char data[DATA_SIZE];
	bert_buffer_t buffer;

	memset(data,'A',DATA_SIZE);

	bert_buffer_init(&buffer);

	bert_buffer_write(&buffer,data,DATA_SIZE);

	if (!(buffer.head))
	{
		test_fail("bert_buffer_write did not allocate any chunks");
	}

	size_t length = buffer.head->length;

	if (length != DATA_SIZE)
	{
		test_fail("bert_buffer_write wrote %u bytes, expected %u bytes",length,DATA_SIZE);
	}

	const unsigned char *result = buffer.head->data;

	if (memcmp(result,"AAAA",DATA_SIZE))
	{
		test_fail("bert_buffer_write wrote %c%c%c%c, expected AAAA",result[0],result[1],result[2],result[3]);
	}

	return 0;
}
