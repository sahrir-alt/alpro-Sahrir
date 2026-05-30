#include <iostream>
#include <string>
#include <ctime>

using namespace std;

#define COLOR_RESET   "\033[0m"
#define COLOR_GREEN   "\033[1;32m"
#define COLOR_GRAY    "\033[0;90m"
#define COLOR_RED     "\033[1;31m"

struct Commit {
    int id;
    string hash;
    string pesan;
    string penulis;
    string waktu;
    Commit* next;
};

struct Branch {
    string nama;
    Commit* head;
    int jumlah_commit;
    Branch* next;
};

struct Repository {
    string nama;
    Branch* daftar_branch;
    Branch* branch_aktif;
    int jumlah_branch;
    int total_commit;
    Repository* next;
};

Repository* daftar_repo  = nullptr;
Repository* repo_aktif   = nullptr;
int jumlah_repo          = 0;
string nama_author       = "";
int id_commit_global     = 1;

void clear_screen() {
    system("cls");
}

void tekan_enter() {
    cout << COLOR_GRAY << "\nPress Enter..." << COLOR_RESET;
    cin.ignore();
    cin.get();
}

Repository* buat_repo(const string& nama) {
    Repository* repo = new Repository;
    repo->nama = nama;
    repo->jumlah_branch = 1;
    repo->total_commit = 0;
    repo->next = nullptr;

    Branch* branch_utama = new Branch;
    branch_utama->nama = "main";
    branch_utama->head = nullptr;
    branch_utama->jumlah_commit = 0;
    branch_utama->next = nullptr;

    repo->daftar_branch = branch_utama;
    repo->branch_aktif  = branch_utama;

    return repo;
}

void tambah_repo(Repository* repo) {
    if (!daftar_repo) {
        daftar_repo = repo;
    } else {
        Repository* saat_ini = daftar_repo;
        while (saat_ini->next) saat_ini = saat_ini->next;
        saat_ini->next = repo;
    }
    jumlah_repo++;
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        cout << COLOR_RED << "Usage: ./gitsim <Username>\n" << COLOR_RESET;
        return 1;
    }

    nama_author = argv[1];

    clear_screen();
    cout << COLOR_GREEN << "GITSIM" << COLOR_RESET << " - Lightweight Git Simulator\n";
    cout << "Author: " << COLOR_GREEN << nama_author << COLOR_RESET << "\n";
    cout << COLOR_GRAY << "----------------------------------------" << COLOR_RESET << "\n";
    cout << "git init\n";
    cout << COLOR_GRAY << "----------------------------------------" << COLOR_RESET << "\n";
    cout << COLOR_GREEN << "Repository name: " << COLOR_RESET;

    string nama_repo;
    getline(cin, nama_repo);
    if (nama_repo.empty()) nama_repo = "my-repo";

    Repository* repo_pertama = buat_repo(nama_repo);
    tambah_repo(repo_pertama);
    repo_aktif = repo_pertama;

    cout << "\n" << COLOR_GREEN << "[OK] Initialized empty repository: " << nama_repo << "\n" << COLOR_RESET;
    cout << "On branch: " << COLOR_GREEN << "main" << COLOR_RESET << "\n";
    tekan_enter();

    return 0;
}