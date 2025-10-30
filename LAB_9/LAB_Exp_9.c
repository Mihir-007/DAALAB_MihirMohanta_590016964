#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    char ch;
    int freq;
    struct node *left, *right;
};

struct node* create_node(char ch, int freq) {
    struct node* n = (struct node*)malloc(sizeof(struct node));
    n->ch = ch;
    n->freq = freq;
    n->left = n->right = NULL;
    return n;
}

struct node* extract_min(struct node* nodes[], int *n) {
    int min = 0;
    for (int i = 1; i < *n; i++)
        if (nodes[i]->freq < nodes[min]->freq) min = i;
    struct node* temp = nodes[min];
    for (int i = min; i < *n - 1; i++) nodes[i] = nodes[i + 1];
    (*n)--;
    return temp;
}

struct node* build_tree(char data[], int freq[], int n) {
    struct node* nodes[256];
    for (int i = 0; i < n; i++) nodes[i] = create_node(data[i], freq[i]);
    while (n > 1) {
        struct node* left = extract_min(nodes, &n);
        struct node* right = extract_min(nodes, &n);
        struct node* top = create_node('$', left->freq + right->freq);
        top->left = left;
        top->right = right;
        nodes[n++] = top;
    }
    return nodes[0];
}

void print_codes(struct node* root, char code[], int top, char codes[256][100]) {
    if (root->left) { code[top] = '0'; print_codes(root->left, code, top + 1, codes); }
    if (root->right) { code[top] = '1'; print_codes(root->right, code, top + 1, codes); }
    if (!root->left && !root->right) {
        code[top] = '\0';
        strcpy(codes[(unsigned char)root->ch], code);
        printf("%c : %s\n", root->ch, code);
    }
}

void calculate_freq(char str[], char data[], int freq[], int *n) {
    int count[256] = {0};
    for (int i = 0; str[i]; i++) count[(unsigned char)str[i]]++;
    *n = 0;
    for (int i = 0; i < 256; i++)
        if (count[i]) {
            data[*n] = i;
            freq[*n] = count[i];
            (*n)++;
        }
}

int main() {
    char str[100], data[256], code[100], codes[256][100];
    int freq[256], n;
    printf("enter text: ");
    gets(str);
    calculate_freq(str, data, freq, &n);
    printf("\ncharacter frequencies:\n");
    for (int i = 0; i < n; i++) printf("%c : %d\n", data[i], freq[i]);
    struct node* root = build_tree(data, freq, n);
    printf("\nhuffman codes:\n");
    print_codes(root, code, 0, codes);
    printf("\nencoded string: ");
    for (int i = 0; str[i]; i++) printf("%s", codes[(unsigned char)str[i]]);
    printf("\ndecoded string: %s\n", str);
    return 0;
}