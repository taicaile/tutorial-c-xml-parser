#include "stdio.h"
#include "lxml.h"

int main()
{
    XMLDocument doc;
    if (XML_Document_load(&doc, "test.xml"))
    {
        printf("%s: %s\n", doc.root->tag, doc.root->inner_text);
        XML_Document_free(&doc);
    }

    return 0;
}
