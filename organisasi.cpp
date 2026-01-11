#include "Organisasi.h"

// Constructor
Organisasi::Organisasi() {
    root = NULL;
}

// Cari node secara rekursif
Node* Organisasi::cariNode(Node* node, string jabatan) {
    if (node == NULL)
        return NULL;

    if (node->jabatan == jabatan)
        return node;

    Node* hasil = cariNode(node->firstChild, jabatan);
    if (hasil != NULL)
        return hasil;

    return cariNode(node->nextSibling, jabatan);
}

// Tambah jabatan
void Organisasi::tambahJabatan(string parentJabatan, string jabatanBaru) {
    Node* nodeBaru = new Node;
    nodeBaru->jabatan = jabatanBaru;
    nodeBaru->parent = NULL;
    nodeBaru->firstChild = NULL;
    nodeBaru->nextSibling = NULL;

    // Jika root belum ada
    if (root == NULL) {
        root = nodeBaru;
        cout << "Root berhasil dibuat.\n";
        return;
    }

    Node* parent = cariNode(root, parentJabatan);
    if (parent == NULL) {
        cout << "Parent tidak ditemukan.\n";
        delete nodeBaru;
        return;
    }

    nodeBaru->parent = parent;

    if (parent->firstChild == NULL) {
        parent->firstChild = nodeBaru;
    } else {
        Node* temp = parent->firstChild;
        while (temp->nextSibling != NULL) {
            temp = temp->nextSibling;
        }
        temp->nextSibling = nodeBaru;
    }

    cout << "Jabatan berhasil ditambahkan.\n";
}

// Hapus subtree (rekursif)
void Organisasi::hapusSubtree(Node* node) {
    if (node == NULL)
        return;

    hapusSubtree(node->firstChild);
    hapusSubtree(node->nextSibling);
    delete node;
}

// Hapus jabatan
void Organisasi::hapusJabatan(string jabatan) {
    if (root == NULL) {
        cout << "Struktur organisasi kosong.\n";
        return;
    }

    Node* target = cariNode(root, jabatan);
    if (target == NULL) {
        cout << "Jabatan tidak ditemukan.\n";
        return;
    }

    if (target == root) {
        cout << "Root tidak boleh dihapus.\n";
        return;
    }

    Node* parent = target->parent;

    // Jika target adalah anak pertama
    if (parent->firstChild == target) {
        parent->firstChild = target->nextSibling;
    }
    else {
        Node* temp = parent->firstChild;
        while (temp != NULL && temp->nextSibling != target) {
            temp = temp->nextSibling;
        }
        if (temp != NULL) {
            temp->nextSibling = target->nextSibling;
        }
    }

    target->nextSibling = NULL;
    hapusSubtree(target);

    cout << "Jabatan berhasil dihapus.\n";
}

// Tampilkan struktur organisasi
void Organisasi::tampilkan(Node* node, int level) {
    if (node == NULL)
        return;

    for (int i = 0; i < level; i++)
        cout << "  ";

    cout << node->jabatan << endl;

    tampilkan(node->firstChild, level + 1);
    tampilkan(node->nextSibling, level);
}

// Public tampil
void Organisasi::tampilStruktur() {
    if (root == NULL) {
        cout << "Struktur organisasi masih kosong.\n";
        return;
    }
    tampilkan(root, 0);
}
