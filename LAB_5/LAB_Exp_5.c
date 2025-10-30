#include <stdio.h>
#include <stdlib.h>

struct Node {
    char ch;
    int freqency;
    struct Node *left, *right;
};

struct Node* createNode(char ch, int freq) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->ch = ch;
    node->freqency = freq;
    node->left = node->right = NULL;
    return node;
}

int findMin(struct Node* nodes[], int size) {
    int min = 0;
    for (int i = 1; i < size; i++) {
        if (nodes[i]->freqency < nodes[min]->freqency) {
            min = i;
        }
    }
    return min;
}

struct Node* buildHuffmanTree(char data[], int freq[], int size) {
    struct Node* nodes[100];
    for (int i = 0; i < size; i++) {
        nodes[i] = createNode(data[i], freq[i]);
    }
    int n = size;
    while (n > 1) {
        int i1 = findMin(nodes, n);
        struct Node* left = nodes[i1];
        nodes[i1] = nodes[n - 1]; 
        n--;
        
        int i2 = findMin(nodes, n);
        struct Node* right = nodes[i2];
        nodes[i2] = nodes[n - 1];
        n--;

        struct Node* parent = createNode('$', left->freqency + right->freqency);
        parent->left = left;
        parent->right = right;
        nodes[n++] = parent;
    }
    return nodes[0];
}

void printCodes(struct Node* root, int code[], int top) {
    if (!root) return;
    if (root->left) {
        code[top] = 0;
        printCodes(root->left, code, top + 1);
    }
    if (root->right) {
        code[top] = 1;
        printCodes(root->right, code, top + 1);
    }
    if (!root->left && !root->right) {
        printf("%c: ", root->ch);
        for (int i = 0; i < top; i++) printf("%d", code[i]);
        printf("\n");
    }
}

int main() {
    char arr[] = { 'a', 'b', 'c', 'd', 'e', 'f' };
    int freq[] = { 5, 9, 12, 13, 16, 45 };
    int size = sizeof(arr) / sizeof(arr[0]);

    struct Node* root = buildHuffmanTree(arr, freq, size);

    printf("Huffman Codes:\n");
    int code[100];
    printCodes(root, code, 0);
    return 0;
}