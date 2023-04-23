#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<stdint.h>
#include<string.h>
#include<strings.h>
#include<ctype.h>

#define ISspace(x) isspace((int)(x))

#define SERVER_STRING "Server:jdbhttpd/0.10\r\n"
#define STDIN 0
#define STDOUT 1
#define STDERR 2

void accept_request(void*);
void bad_request(int);
void cat(int, FILE*);
void cannot_execute(int);
void error_die(const char*);
void execute_cgi(int, const char*, const char*, const char*);
int get_line(int, char*, int);
void headers(int, const char*);
void not_found(int);
void serve_file(int);
void startup(u_short*);
void unimplemented(int);

void accept_request(void* arg)
{
	int client = (intptr_t)arg;
	char buf[1024];
	size_t numchars;
	char method[255];
	char url[255];
	char path[512];
	size_t i, j;
	struct stat st;
	int cgi = 0;

	char* query_string = NULL;
	numchars = get_line(client, buf, sizeof(buf));
	i = 0; j = 0;
	while (!ISspace(buf[i]) && (i < sizeof(method) - 1))
	{
		method[i] = buf[i];
		i++;
	}
	j = i;
	method[i] = '\0';

}