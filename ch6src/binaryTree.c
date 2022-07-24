#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct tnode
{
    char *text;
    int count;
    struct tnode *leftChild;
    struct tnode *rightChild;
};

struct tnode *loadWords();
struct tnode *insertWord(struct tnode *root, char *word);
struct tnode *searchWord(struct tnode *root, char *word);
void printTree(struct tnode *root);

int main(int argc, char *argv[])
{
    struct tnode *root = loadWords();

    printTree(root);

    struct tnode *wordNode = searchWord(root, "leandro");

    if (wordNode != NULL)
    {
        printf("leandro found %d times", wordNode->count);
    }

    return 0;
}

struct tnode *searchWord(struct tnode *root, char *word)
{
    if (root == NULL)
    {
        return NULL;
    }

    if (strcmp(word, root->text) == 0)
    {
        return root;
    }
    else
    {
        if (strcmp(word, root->text) < 0)
        {
            searchWord(root->leftChild, word);
        }
        else
        {
            searchWord(root->rightChild, word);
        }
    }
}

struct tnode *insertWord(struct tnode *root, char *word)
{
    if (root == NULL)
    {
        root = (struct tnode *)malloc(sizeof(struct tnode));
        root->count = 1;
        root->leftChild = NULL;
        root->rightChild = NULL;
        root->text = word;
    }
    else
    {
        if (strcmp(word, root->text) == 0)
        {
            root->count++;
        }
        else if (strcmp(word, root->text) < 0)
        {
            root->leftChild = insertWord(root->leftChild, word);
        }
        else
        {
            root->rightChild = insertWord(root->rightChild, word);
        }
    }

    return root;
}

struct tnode *loadWords()
{
    int const LINEMAX = 100;
    char *lineBuf;
    struct tnode *root = NULL;

    int scanReturn = scanf("%s", lineBuf = malloc(LINEMAX));

    while (scanReturn != EOF)
    {
        if (lineBuf == NULL)
        {
            return NULL;
        }
        else
        {
            if (root == NULL)
            {
                root = insertWord(root, lineBuf);
            }
            else
            {
                insertWord(root, lineBuf);
            }
        }

        scanReturn = scanf("%s", lineBuf = malloc(LINEMAX));
    }

    return root;
}

void printTree(struct tnode *root)
{
    if (root != NULL)
    {
        printTree(root->leftChild);
        printf("| %s : %d times |", root->text, root->count);
        printTree(root->rightChild);
    }
}