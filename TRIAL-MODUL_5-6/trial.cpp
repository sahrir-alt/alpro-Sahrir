#include <iostream>
#include <string>
#include <ctime>

using namespace std;

#define COLOR_RESET   "\033[0m"
#define COLOR_GREEN   "\033[1;32m"
#define COLOR_GRAY    "\033[0;90m"
#define COLOR_RED     "\033[1;31m"
#define COLOR_BLUE    "\033[1;34m"
#define COLOR_CYAN    "\033[1;36m"

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
int index_repo(Repository* repo) {
    Repository* saat_ini = daftar_repo;
    int idx = 1;
    while (saat_ini) {
        if (saat_ini == repo) return idx;
        idx++;
        saat_ini = saat_ini->next;
    }
    return -1;
}

void cetak_header() {
    cout << COLOR_BLUE << "GITSIM" << COLOR_RESET << " - Git Simulator\n";
    cout << "Author : " << COLOR_GREEN << nama_author << COLOR_RESET;
    cout << "  |  Repo: " << COLOR_GREEN << repo_aktif->nama << COLOR_RESET;
    cout << "  |  HEAD: " << COLOR_GREEN << repo_aktif->branch_aktif->nama << COLOR_RESET;
    cout << "  |  [" << COLOR_GREEN << index_repo(repo_aktif) << COLOR_RESET
         << "/" << COLOR_GREEN << jumlah_repo << COLOR_RESET << "]\n";
    cout << COLOR_GRAY << "----------------------------------------" << COLOR_RESET << "\n";
}

string buat_hash(int id_commit) {
    const char hex[] = "0123456789abcdef";
    string hash = "";
    int nilai = id_commit * 2654435761u;
    if (nilai < 0) nilai = -nilai;
    for (int i = 0; i < 7; i++) {
        hash = hex[nilai & 0xF] + hash;
        nilai = nilai >> 4;
    }
    return hash;
}

string ambil_waktu() {
    time_t sekarang = time(nullptr);
    char buffer[20];
    strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M", localtime(&sekarang));
    return string(buffer);
}

void git_commit() {
    clear_screen();
    cout << COLOR_BLUE   << "GITSIM" << COLOR_RESET << " - Git Simulator\n";
    cout << "Author: " << COLOR_GRAY << nama_author << COLOR_RESET << "\n";
    cout << COLOR_GRAY << "----------------------------------------" << COLOR_RESET << "\n";
    cout << "git commit [" << COLOR_GREEN << repo_aktif->branch_aktif->nama << COLOR_RESET << "]\n";
    cout << COLOR_GRAY << "----------------------------------------" << COLOR_RESET << "\n";

    cout << COLOR_GREEN << "Message : " << COLOR_RESET;
    string pesan;
    cin.ignore();
    getline(cin, pesan);

    cout << COLOR_GREEN << "Push commit? (y/n): " << COLOR_RESET;
    char konfirmasi;
    cin >> konfirmasi;
    cin.ignore();

    if (konfirmasi != 'y' && konfirmasi != 'Y') {
        cout << COLOR_RED << "[ABORTED] Commit dibatalkan.\n" << COLOR_RESET;
        tekan_enter();
        return;
    }

    Commit* c  = new Commit;
    c->id      = id_commit_global++;
    c->hash    = buat_hash(c->id);
    c->pesan   = pesan;
    c->penulis = nama_author;
    c->waktu   = ambil_waktu();
    c->next    = repo_aktif->branch_aktif->head;

    repo_aktif->branch_aktif->head = c;
    repo_aktif->branch_aktif->jumlah_commit++;
    repo_aktif->total_commit++;

    string nama_branch = repo_aktif->branch_aktif->nama;
    cout << "\n[" << COLOR_GREEN << nama_branch << " " << c->hash << COLOR_RESET << "] " << pesan << "\n";
    cout << COLOR_GRAY << "----------------------------------------" << COLOR_RESET << "\n";
    cout << COLOR_GREEN << nama_branch << COLOR_RESET << " -> " << COLOR_GREEN << "origin/" << nama_branch << COLOR_RESET << "\n";
    cout << "$ git push origin " << COLOR_GREEN << nama_branch << COLOR_RESET << "\n";
    cout << COLOR_GRAY << "----------------------------------------" << COLOR_RESET << "\n";

    tekan_enter();
}

void git_log() {
    clear_screen();
    cout << COLOR_BLUE << "GITSIM" << COLOR_RESET << " - Git Simulator\n";
    cout << COLOR_GREEN << "Author: " COLOR_RESET << nama_author << "\n";
    cout << COLOR_GRAY << "----------------------------------------" << COLOR_RESET << "\n";
    cout << "git log [" << COLOR_GREEN << repo_aktif->branch_aktif->nama << COLOR_RESET << "]\n";
    cout << COLOR_GRAY << "----------------------------------------" << COLOR_RESET << "\n";

    Commit* c = repo_aktif->branch_aktif->head;
    if (!c) {
        cout << "(No commits on this branch)\n";
    } else {
        while (c) {
            cout << COLOR_GREEN << "commit " << c->hash << COLOR_RESET << "\n";
            cout << "Author : " << COLOR_GREEN << c->penulis << COLOR_RESET << "\n";
            cout << "Date   : " << COLOR_GREEN << c->waktu << COLOR_RESET << "\n";
            cout << "        " << c->pesan << "\n";
            if (c->next) cout << "\n";
            c = c->next;
        }
    }

    cout << COLOR_GRAY << "\n----------------------------------------" << COLOR_RESET << "\n";
    tekan_enter();
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        cout << COLOR_RED << "Usage: ./gitsim <Username>\n" << COLOR_RESET;
        return 1;
    }

    nama_author = argv[1];

    clear_screen();
    cout << COLOR_BLUE << "GITSIM" << COLOR_RESET << " - Lightweight Git Simulator\n";
    cout << "Author: " << COLOR_RESET << nama_author << "\n";
    cout << COLOR_GRAY << "----------------------------------------" << COLOR_RESET << "\n";
    cout << "git init\n";
    cout << COLOR_GRAY << "----------------------------------------" << COLOR_RESET << "\n";
    cout << COLOR_CYAN << "Repository name: " << COLOR_RESET;

    string nama_repo;
    getline(cin, nama_repo);
    if (nama_repo.empty()) nama_repo = "my-repo";

    Repository* repo_pertama = buat_repo(nama_repo);
    tambah_repo(repo_pertama);
    repo_aktif = repo_pertama;

    cout << "\n" << COLOR_GREEN << "[OK] " << COLOR_RESET << "Initialized empty repository: " << nama_repo << "\n";
cout << "On branch: " << COLOR_GREEN << "main" << COLOR_RESET << "\n";
    tekan_enter();

    int pilihan = -1;
    while (pilihan != 0) {
        clear_screen();
        cetak_header();
        cout << "[1] git commit\n";
        cout << "[2] git log\n";
        cout << "[0] exit\n";
        cout << COLOR_GRAY << "----------------------------------------" << COLOR_RESET << "\n";
        cout << COLOR_GREEN << "> " << COLOR_RESET;

        cin >> pilihan;
        cin.clear();

        switch (pilihan) {
            case 1: git_commit(); break;
            case 2: git_log(); break;
            case 0: break;
            default:
                cout << COLOR_RED << "[ERROR] Pilihan tidak valid.\n" << COLOR_RESET;
                tekan_enter();
                break;
        }
    }

    clear_screen();
    cout << COLOR_GREEN << "Session Ended\n" << COLOR_RESET;
    cout << "Author : " << COLOR_GREEN << nama_author << COLOR_RESET << "\n";
    cout << COLOR_GREEN << "Goodbye!\n" << COLOR_RESET;


    return 0;
}