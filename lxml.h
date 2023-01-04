#ifndef LITTLE_XML_H
#define LITTLE_XML_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef TRUE
#define TRUE 1
#endif

#ifndef FALSE
#define FALSE 0
#endif

//
// Definitions
//

struct _XML_Document
{
    char *source;
};
typedef struct _XML_Document XMLDocument;

int XML_Document_load(XMLDocument *doc, const char *path);
void XML_Document_free(XMLDocument *doc);

//
// Implementation
//
int XML_Document_load(XMLDocument *doc, const char *path)
{
    FILE *file = fopen(path, "r");
    if (!file)
    {
        fprintf(stderr, "Could not load file from '%s'\n", path);
        return FALSE;
    }
    fseek(file, 0, SEEK_END);
    int size = ftell(file);
    fseek(file, 0, SEEK_SET);

    doc->source = (char *)malloc(sizeof(size) + 1);
    fread(doc->source, 1, size, file);
    doc->source[size] = '\0';
    return TRUE;
}

void XML_Document_free(XMLDocument *doc)
{
    free(doc->source);
}

#endif
