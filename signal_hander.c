#include "header.h"
/**
 * sig_handler - handler ctrl + c.
 * @i: integer.
 */

void sig_handler(int i)
{
	(void)i;
	_pstr("\n$ ");
}
