#ifndef ORGANISASI_H
#define ORGANISASI_H

#include <iostream>
using namespace std;

struct Node {
    string jabatan;
    Node* parent;
    Node* firstChild;
    Node* nextSibling;
};

class Organisasi {
private:
    Node* root;

    Node* cariNode(Node* node, string jabatan);
    void tampilkan(Node* node, int level);
    void hapusSubtree(Node* node);

public:
    Organisasi();
    void tambahJabatan(string parentJabatan, string jabatanBaru);
    void hapusJabatan(string jabatan);
    void tampilStruktur();
};

#endif
