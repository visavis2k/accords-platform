/* -------------------------------------------------------------------- */
/*  ACCORDS PLATFORM                                                    */
/*  (C) 2011 by Iain James Marshall (Prologue) <ijm667@hotmail.com>     */
/* -------------------------------------------------------------------- */
/* Licensed under the Apache License, Version 2.0 (the "License"); 	*/
/* you may not use this file except in compliance with the License. 	*/
/* You may obtain a copy of the License at 				*/
/*  									*/
/*  http://www.apache.org/licenses/LICENSE-2.0 				*/
/*  									*/
/* Unless required by applicable law or agreed to in writing, software 	*/
/* distributed under the License is distributed on an "AS IS" BASIS, 	*/
/* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or 	*/
/* implied. 								*/
/* See the License for the specific language governing permissions and 	*/
/* limitations under the License. 					*/
/* -------------------------------------------------------------------- */

/* STRUKT WARNING : this file has been generated and should not be modified by hand */
#ifndef _paas_version_c_
#define _paas_version_c_

#include "element.h"

#include "paas_version.h"

/*	------------------------------------------	*/
/*	l i b e r a t e _ p a a s _ v e r s i o n 	*/
/*	------------------------------------------	*/
public struct paas_version * liberate_paas_version(struct paas_version * sptr)
{
	if ( sptr )
	{
		if ( sptr->id )
			 sptr->id = liberate(sptr->id);
		if ( sptr->label )
			 sptr->label = liberate(sptr->label);
		if ( sptr->date_updated )
			 sptr->date_updated = liberate(sptr->date_updated);
		if ( sptr->description )
			 sptr->description = liberate(sptr->description);
		sptr = liberate( sptr );
	}
	return((struct paas_version *) 0);

}

/*	------------------------------------	*/
/*	r e s e t _ p a a s _ v e r s i o n 	*/
/*	------------------------------------	*/
public struct paas_version * reset_paas_version(struct paas_version * sptr)
{
	if ( sptr )
	{
		sptr->id = (char*) 0;
		sptr->label = (char*) 0;
		sptr->date_updated = (char*) 0;
		sptr->description = (char*) 0;
		sptr->state =  0;
	}
	return(sptr);

}

/*	------------------------------------------	*/
/*	a l l o c a t e _ p a a s _ v e r s i o n 	*/
/*	------------------------------------------	*/
public struct paas_version * allocate_paas_version()
{
	struct paas_version * sptr;
	if (!( sptr = allocate( sizeof( struct paas_version ) ) ))
		return( sptr );
	else	return( reset_paas_version(sptr) );
}

/*	------------------------------------	*/
/*	x m l i n _ p a a s _ v e r s i o n 	*/
/*	------------------------------------	*/
public int xmlin_paas_version(struct paas_version * sptr,struct xml_element * eptr)
{
	struct xml_element * wptr;
	if (!( eptr )) return(0);
	if (!( sptr )) return(0);
	for ( wptr=eptr->first; wptr != (struct xml_element *) 0; wptr=wptr->next)
	{
		if (!( strcmp(wptr->name,"id") ))
		{
			if ( wptr->value ) { sptr->id = allocate_string(wptr->value); }
		}
		else if (!( strcmp(wptr->name,"label") ))
		{
			if ( wptr->value ) { sptr->label = allocate_string(wptr->value); }
		}
		else if (!( strcmp(wptr->name,"date_updated") ))
		{
			if ( wptr->value ) { sptr->date_updated = allocate_string(wptr->value); }
		}
		else if (!( strcmp(wptr->name,"description") ))
		{
			if ( wptr->value ) { sptr->description = allocate_string(wptr->value); }
		}
		else if (!( strcmp(wptr->name,"state") ))
		{
			if ( wptr->value ) { sptr->state = atoi(wptr->value); }
		}
	}
	return(0);

}

/*	--------------------------------------------	*/
/*	r e s t _ o c c i _ p a a s _ v e r s i o n 	*/
/*	--------------------------------------------	*/
public int rest_occi_paas_version(FILE * fh,struct paas_version * sptr,char * prefix, char * nptr)
{
	struct xml_element * wptr;
	if (!( sptr )) return(0);
	fprintf(fh,"POST /%s/ HTTP/1.1\r\n",nptr);
	fprintf(fh,"Category: %s; scheme='http://scheme.%s.org/occi/%s#'; class='kind';\r\n",nptr,prefix,prefix);
	fprintf(fh,"X-OCCI-Attribute: %s.%s.id='%s'\r\n",prefix,nptr,(sptr->id?sptr->id:""));
	fprintf(fh,"X-OCCI-Attribute: %s.%s.label='%s'\r\n",prefix,nptr,(sptr->label?sptr->label:""));
	fprintf(fh,"X-OCCI-Attribute: %s.%s.date_updated='%s'\r\n",prefix,nptr,(sptr->date_updated?sptr->date_updated:""));
	fprintf(fh,"X-OCCI-Attribute: %s.%s.description='%s'\r\n",prefix,nptr,(sptr->description?sptr->description:""));
	fprintf(fh,"X-OCCI-Attribute: %s.%s.state='%u'\r\n",prefix,nptr,sptr->state);
	return(0);

}

#endif	/* _paas_version_cpaas_version_c_ */