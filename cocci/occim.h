#ifndef	_occim_h
#define	_occim_h

#ifndef	_occi_manager

struct	occi_manager	
{
	struct	occi_header_manager 	* headers;
	int				mode;
	struct	occi_client 		* first;
	struct	occi_client 		* last;
	char 				* name;
	char				* mimetype;
	char				* accepts;
	char				* eventlog;
	int			  clients;
	int			  optimise;
};

#endif

#endif	

