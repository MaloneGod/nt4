/***
*fsetpos.c - Contains fsetpos runtime
*
*	Copyright (c) 1987-1991, Microsoft Corporation. All rights reserved.
*
*Purpose:
*	Fsetpos sets the file position using an internal value
*	returned by an earlier fgetpos call.
*
*Revision History:
*	01-16-87  JCR	Module created
*	04-13-87  JCR	Added const to declaration
*	12-11-87  JCR	Added "_LOAD_DS" to declaration
*	02-15-90  GJF	Fixed copyright and indents
*	03-19-90  GJF	Replaced _LOAD_DS with _CALLTYPE1 and added #include
*			<cruntime.h>.
*	10-02-90  GJF	New-style function declarators.
*
*******************************************************************************/

#include <cruntime.h>
#include <stdio.h>

/***
*int fsetpos(stream,pos) - Set file positioning
*
*Purpose:
*	Fsetpos sets the file position for the file indicated by [stream] to
*	the position indicated by [pos].  The [pos] value is defined to be in
*	an internal format (not to be interpreted by the user) and has been
*	generated by an earlier fgetpos call.
*
*Entry:
*	FILE *stream = pointer to a file stream value
*	fpos_t *pos = pointer to a file positioning value
*
*Exit:
*	Successful call returns 0.
*	Unsuccessful call returns non-zero (!0).
*
*Exceptions:
*	None.
*******************************************************************************/

int _CALLTYPE1 fsetpos (
	FILE *stream,
	const fpos_t *pos
	)
{
	return(fseek(stream,*pos,SEEK_SET));
}
