#include "Organisasi.h"

int main() {
    Organisasi hima;
    int pilihan;
    string parent, jabatan;

    do {
        cout << "\nMENU STRUKTUR ORGANISASI HIMA\n";
        cout << "1. Tambah Jabatan\n";
        cout << "2. Tampilkan Struktur\n";
        cout << "3. Hapus Jabatan\n";
        cout << "4. Keluar\n";
        cout << "Pilih menu: ";
        cin >> pilihan;
        cin.ignore();

        if (pilihan == 1) {
            cout << "Masukkan parent jabatan: ";
            getline(cin, parent);

            cout << "Masukkan nama jabatan: ";
            getline(cin, jabatan);

            hima.tambahJabatan(parent, jabatan);
        }
        else if (pilihan == 2) {
            cout << "\nSTRUKTUR ORGANISASI:\n";
            hima.tampilStruktur();
        }
        else if (pilihan == 3) {
            cout << "Masukkan jabatan yang ingin dihapus: ";
            getline(cin, jabatan);
            hima.hapusJabatan(jabatan);
        }

    } while (pilihan != 4);

    cout << "Program selesai.\n";
    return 0;
}
