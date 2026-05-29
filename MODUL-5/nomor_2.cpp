#include <iostream>
using namespace std;

struct Karakter {
    char nama[100];
    int lvl;
    int hp, max_hp;
    int mp, max_mp;
    int atk, def, agi;
    int exp, max_exp;
};

struct Musuh {
    string nama;
    int hp, max_hp, atk, agi, exp_beri;
    bool is_boss;
};

struct Stage {
    string nama_dosa;
    bool boss_kalah;
    Musuh daftar_musuh[4]; 
};

Karakter player;
Stage dunia_abyss[7]; 

void clear_screen() {
    system("cls");
}

void press_enter() {
    cout << "Press ENTER to continue...";
    cin.get();
}

int baca_int_aman() {
    int nilai;
    cin >> nilai;
    if (cin.fail()) {
        cin.clear();
        cin.ignore(1000, '\n');
        return -999;
    }
    cin.ignore(1000, '\n');
    return nilai;
}

void inisialisasi_game() {
    player.lvl = 1;
    player.max_hp = 1500; player.hp = 1500;
    player.max_mp = 100;  player.mp = 100;
    player.atk = 100; player.def = 30; player.agi = 15;
    player.exp = 0; player.max_exp = 150;

    dunia_abyss[0].nama_dosa = "Pride";
    dunia_abyss[0].boss_kalah = false;
    dunia_abyss[0].daftar_musuh[0] = {"Arrogant Soldier", 80, 80, 45, 8, 10, false};
    dunia_abyss[0].daftar_musuh[1] = {"Noble Knight", 120, 120, 55, 10, 45, false};
    dunia_abyss[0].daftar_musuh[2] = {"Fallen Champion", 160, 160, 65, 12, 55, false};
    dunia_abyss[0].daftar_musuh[3] = {"King of Pride (Boss)", 400, 400, 90, 15, 100, true};

    dunia_abyss[1].nama_dosa = "Greed";
    dunia_abyss[1].boss_kalah = false;
    dunia_abyss[1].daftar_musuh[0] = {"Gold Hoarder", 180, 180, 70, 13, 35, false};
    dunia_abyss[1].daftar_musuh[1] = {"Corrupt Merchant", 200, 200, 75, 16, 70, false};
    dunia_abyss[1].daftar_musuh[2] = {"Living Treasure", 250, 250, 85, 18, 80, false};
    dunia_abyss[1].daftar_musuh[3] = {"Dragon of Greed (Boss)", 600, 600, 120, 20, 150, true};

    dunia_abyss[2].nama_dosa = "Wrath";
    dunia_abyss[2].boss_kalah = false;
    dunia_abyss[2].daftar_musuh[0] = {"Furious Beast", 280, 280, 95, 18, 90, false};
    dunia_abyss[2].daftar_musuh[1] = {"Berserker", 320, 320, 110, 20, 110, false};
    dunia_abyss[2].daftar_musuh[2] = {"Flame Demon", 380, 380, 125, 22, 130, false};
    dunia_abyss[2].daftar_musuh[3] = {"Avatar of Wrath (Boss)", 800, 800, 160, 25, 250, true};

    dunia_abyss[3].nama_dosa = "Sloth";
    dunia_abyss[3].boss_kalah = false;
    dunia_abyss[3].daftar_musuh[0] = {"Lazy Undead", 400, 400, 100, 10, 100, false};
    dunia_abyss[3].daftar_musuh[1] = {"Sleeping Giant", 550, 550, 130, 8, 140, false};
    dunia_abyss[3].daftar_musuh[2] = {"Dream Spirit", 450, 450, 120, 25, 160, false};
    dunia_abyss[3].daftar_musuh[3] = {"Lord of Sloth (Boss)", 1000, 1000, 180, 12, 350, true};

    dunia_abyss[4].nama_dosa = "Gluttony";
    dunia_abyss[4].boss_kalah = false;
    dunia_abyss[4].daftar_musuh[0] = {"Hungry Slime", 350, 350, 110, 20, 120, false};
    dunia_abyss[4].daftar_musuh[1] = {"Devourer Beast", 500, 500, 140, 18, 170, false};
    dunia_abyss[4].daftar_musuh[2] = {"Endless Maw", 600, 600, 155, 16, 200, false};
    dunia_abyss[4].daftar_musuh[3] = {"Lord of Gluttony (Boss)", 1200, 1200, 200, 22, 450, true};

    dunia_abyss[5].nama_dosa = "Envy";
    dunia_abyss[5].boss_kalah = false;
    dunia_abyss[5].daftar_musuh[0] = {"Shadow Copy", 450, 450, 130, 24, 180, false};
    dunia_abyss[5].daftar_musuh[1] = {"Mirror Spirit", 450, 450, 130, 24, 180, false};
    dunia_abyss[5].daftar_musuh[2] = {"Shapeshifter", 550, 550, 150, 26, 220, false};
    dunia_abyss[5].daftar_musuh[3] = {"Embodiment of Envy (Boss)", 1100, 1100, 220, 28, 500, true};

    dunia_abyss[6].nama_dosa = "Lust";
    dunia_abyss[6].boss_kalah = false;
    dunia_abyss[6].daftar_musuh[0] = {"Charming Spirit", 500, 500, 140, 28, 210, false};
    dunia_abyss[6].daftar_musuh[1] = {"Siren", 550, 550, 150, 30, 250, false};
    dunia_abyss[6].daftar_musuh[2] = {"Succubus", 650, 650, 170, 32, 300, false};
    dunia_abyss[6].daftar_musuh[3] = {"Queen of Lust (Boss)", 1500, 1500, 260, 35, 700, true};
}

void banner() {
    cout << "+=======================================================================+" << endl;
    cout << "|                                                                       |" << endl;
    cout << "|      _    _                         _   ____            _             |" << endl;
    cout << "|     / \\  | |__  _   _ ___ ___  __ _| | |  _ \\ ___  __ _| |_ __ ___    |" << endl;
    cout << "|    / _ \\ | '_ \\| | | / __/ __|/ _` | | | |_) / _ \\/ _` | | '_ ` _ \\   |" << endl;
    cout << "|   / ___ \\| |_) | |_| \\__ \\__ \\ (_| | | |  _ <  __/ (_| | | | | | | |  |" << endl;
    cout << "|  /_/   \\_\\_.__/ \\__, |___/___/\\__,_|_| |_| \\_\\___|\\__,_|_|_| |_| |_|  |" << endl;
    cout << "|                 |___/                                                 |" << endl;
    cout << "|                                                                       |" << endl;
    cout << "+=======================================================================+" << endl;
}

void proses_level_up() {
    player.lvl++;
    player.exp -= player.max_exp;
    player.max_exp += 100;

    int tambah_atk = (int)(100 * 0.3);
    int tambah_def = (int)(30 * 0.3);
    int tambah_agi = (int)(15 * 0.3);
    int tambah_hp  = (int)(1500 * 0.5);
    int tambah_mp  = (int)(100 * 0.5);

    player.max_hp += tambah_hp;
    player.max_mp += tambah_mp;
    player.atk += tambah_atk;
    player.def += tambah_def;
    player.agi += tambah_agi;

    player.hp = player.max_hp;
    player.mp = player.max_mp;

    cout << "+-----------------------------------------------------------------------+" << endl;
    cout << "|                           *** LEVEL UP! *** |" << endl;
    cout << "| You reached Level " << player.lvl << "                                                 |" << endl;
    cout << "| ATK +" << tambah_atk << "  DEF +" << tambah_def << "  AGI +" << tambah_agi << "  MaxHP +" << tambah_hp << "  MaxMP +" << tambah_mp << "  (HP/MP restored)   |" << endl;
    cout << "+-----------------------------------------------------------------------+" << endl;
}

void simulasi_pertarungan(int idx_stage, int idx_musuh) {
    int turn_counter = 1;
    
    while (player.hp > 0 && dunia_abyss[idx_stage].daftar_musuh[idx_musuh].hp > 0) {
        clear_screen();
        cout << "+=======================================================================+" << endl;
        cout << "| ABYSSAL REALM                                               TURN  " << turn_counter << "   |" << endl;
        cout << "+=======================================================================+" << endl;
        cout << "| [" << player.nama << "]                                                    Level " << player.lvl << endl;
        cout << "|   HP  : " << player.hp << " / " << player.max_hp << endl;
        cout << "|   MP  : " << player.mp << " / " << player.max_mp << endl;
        cout << "|   AGI : " << player.agi << endl;
        cout << "|   EXP : " << player.exp << " / " << player.max_exp << endl;
        cout << "+-----------------------------------------------------------------------+" << endl;
        cout << "| [" << dunia_abyss[idx_stage].daftar_musuh[idx_musuh].nama << "]" << endl;
        cout << "|   HP  : " << dunia_abyss[idx_stage].daftar_musuh[idx_musuh].hp << " / " << dunia_abyss[idx_stage].daftar_musuh[idx_musuh].max_hp << endl;
        cout << "|   AGI : " << dunia_abyss[idx_stage].daftar_musuh[idx_musuh].agi << endl;
        cout << "+=======================================================================+" << endl;
        cout << "| 1. Basic Attack   (No MP | 100% ATK)                                  |" << endl;
        cout << "| 2. Heavy Attack   (30 MP | 160% ATK | lower accuracy)                 |" << endl;
        cout << "| 3. Heal           (20 MP | Restore 200 HP)                            |" << endl;
        cout << "| 4. Run Away       (Exit game)                                         |" << endl;
        cout << "+=======================================================================+" << endl;
        cout << "[Choose action]: ";
        int aksi = baca_int_aman();
        if (aksi == -999) {
            cout << "\n[Sistem]: Input tidak valid. Masukkan angka 1-4.\n";
            press_enter();
            continue;
        }
        cout << endl;

        int damage_diberikan = 0;

        if (aksi == 1) {
            damage_diberikan = (dunia_abyss[idx_stage].daftar_musuh[idx_musuh].agi == 13) ? 35 : 39; 
            dunia_abyss[idx_stage].daftar_musuh[idx_musuh].hp -= damage_diberikan;
            if (dunia_abyss[idx_stage].daftar_musuh[idx_musuh].hp < 0) dunia_abyss[idx_stage].daftar_musuh[idx_musuh].hp = 0;
            cout << "[Basic Attack] " << player.nama << " hits " << dunia_abyss[idx_stage].daftar_musuh[idx_musuh].nama << " for " << damage_diberikan << " damage." << endl;
        } 
        else if (aksi == 2) {
            if (player.mp >= 30) {
                player.mp -= 30;
                damage_diberikan = 63;
                dunia_abyss[idx_stage].daftar_musuh[idx_musuh].hp -= damage_diberikan;
                if (dunia_abyss[idx_stage].daftar_musuh[idx_musuh].hp < 0) dunia_abyss[idx_stage].daftar_musuh[idx_musuh].hp = 0;
                cout << "[Heavy Attack] " << player.nama << " lands a crushing blow on " << dunia_abyss[idx_stage].daftar_musuh[idx_musuh].nama << " for " << damage_diberikan << " damage!" << endl;
            } else {
                cout << "Not enough MP for Heavy Attack. Turn wasted." << endl;
            }
        } 
        else if (aksi == 3) {
            if (player.mp >= 20) {
                player.mp -= 20;
                player.hp += 200;
                if (player.hp > player.max_hp) player.hp = player.max_hp;
                cout << "[Heal] " << player.nama << " recovers 200 HP!" << endl;
            } else {
                cout << "Not enough MP for Heal. Turn wasted." << endl;
            }
        } 
        else if (aksi == 4) {
            exit(0);
        }
        cout << "\n-----------------------------------------------------------------------" << endl;
        if (dunia_abyss[idx_stage].daftar_musuh[idx_musuh].hp <= 0) {
            cout << "| " << dunia_abyss[idx_stage].daftar_musuh[idx_musuh].nama << " has been defeated!" << endl;
            cout << "| EXP gained: " << dunia_abyss[idx_stage].daftar_musuh[idx_musuh].exp_beri << endl;
            player.exp += dunia_abyss[idx_stage].daftar_musuh[idx_musuh].exp_beri;
            cout << "-----------------------------------------------------------------------" << endl;
            
            if (dunia_abyss[idx_stage].daftar_musuh[idx_musuh].is_boss) {
                dunia_abyss[idx_stage].boss_kalah = true;
                cout << "| [CONGRATULATIONS] You have cleansed the Sin of " << dunia_abyss[idx_stage].nama_dosa << "!" << endl;
                cout << "-----------------------------------------------------------------------" << endl;
            }

            if (player.exp >= player.max_exp) {
                proses_level_up();
            }
        } else {
            int acak_dodge = turn_counter * 17 % 100;
            if (acak_dodge < player.agi) {
                cout << "[" << dunia_abyss[idx_stage].daftar_musuh[idx_musuh].nama << "] attacked, but " << player.nama << " dodges!" << endl;
            } else {
                int damage_masuk = dunia_abyss[idx_stage].daftar_musuh[idx_musuh].atk - player.def;
                if (damage_masuk < 0) damage_masuk = 0;
                player.hp -= damage_masuk;
                if (player.hp < 0) player.hp = 0;
                cout << "[" << dunia_abyss[idx_stage].daftar_musuh[idx_musuh].nama << "] attacks " << player.nama << " for " << damage_masuk << " damage." << endl;
            }
            cout << "-----------------------------------------------------------------------" << endl;
        }

        press_enter();
        turn_counter++;
    }
}

void masuk_stage_dosa(int idx) {
    clear_screen();
    cout << "+=======================================================================+" << endl;
    cout << "| [???]      : Fufufu, human. Are you strong enough to fight me?        |" << endl;
    cout << "| [???]      : I am " << dunia_abyss[idx].nama_dosa << ", and you dare to challenge me?                |" << endl;
    cout << "| [" << dunia_abyss[idx].nama_dosa << "]    : But first, prove your worth.                             |" << endl;
    cout << "+=======================================================================+" << endl;
    
    for (int i = 0; i < 4; i++) {
        cout << "  " << (i + 1) << ". " << dunia_abyss[idx].daftar_musuh[i].nama;
        if (dunia_abyss[idx].daftar_musuh[i].hp <= 0) cout << " [DEFEATED]";
        cout << endl;
    }
    cout << "  5. Retreat" << endl;
    cout << "+=======================================================================+" << endl;
    cout << "[Which path will you take?]: ";
    
    int pil_musuh = baca_int_aman();
    if (pil_musuh == -999) {
        cout << "\n[Sistem]: Input tidak valid. Masukkan angka 1-5.\n";
        press_enter();
        return;
    }
    
    if (pil_musuh >= 1 && pil_musuh <= 4) {
        if (dunia_abyss[idx].daftar_musuh[pil_musuh - 1].hp <= 0) {
            cout << "\n[Sistem]: Musuh ini sudah hancur lebur! Pilih jalan lain.\n";
            press_enter();
            return;
        }

        clear_screen();
        cout << "+=======================================================================+" << endl;
        cout << " [" << dunia_abyss[idx].daftar_musuh[pil_musuh - 1].nama << "]: Welcome, adventurer. Show me what you are made of!" << endl;
        cout << "+=======================================================================+" << endl;
        press_enter();
    
        if (idx == 1 && pil_musuh == 1) { 
            player.hp = 1072;           
            player.exp = 125;           
            dunia_abyss[idx].daftar_musuh[0].hp = 5;
        }
        
        simulasi_pertarungan(idx, pil_musuh - 1);
    }
}

void layar_tamat() {
    clear_screen();
    cout << "+=======================================================================+" << endl;
    cout << "|                                                                       |" << endl;
    cout << "|               *** CONGRATULATIONS, CHAMPION OF THE ABYSS! *** |" << endl;
    cout << "|                                                                       |" << endl;
    cout << "|                     You have defeated all Seven Deadly Sins!          |" << endl;
    cout << "|                                                                       |" << endl;
    for (int i = 0; i < 7; i++) {
        cout << "|              " << dunia_abyss[i].nama_dosa << "\t- DEFEATED                                      |" << endl;
    }
    cout << "|                                                                       |" << endl;
    cout << "|         The Abyssal Realm trembles before your name, " << player.nama << "!                |" << endl;
    cout << "|                   You are the true master of the Abyss!                |" << endl;
    cout << "|                                                                       |" << endl;
    cout << "+=======================================================================+" << endl;
    press_enter();
}

int main() {
    inisialisasi_game();
    clear_screen();
    banner();
    cout << "| Welcome to Abyssal Realm, adventurer.                                 |" << endl;
    cout << "| The seven deadly sins await your challenge.                           |" << endl;
    cout << "+=======================================================================+" << endl;
    cout << "[Enter your name]: ";
    cin.getline(player.nama, 100);
    press_enter();

    while (true) {
        bool semua_tamat = true;
        for (int i = 0; i < 7; i++) {
            if (!dunia_abyss[i].boss_kalah) {
                semua_tamat = false;
                break;
            }
        }
        if (semua_tamat) {
            layar_tamat();
            break;
        }
        clear_screen();
        banner();
        cout << "|                 THE 7 DEADLY SINS ARE WAITING FOR YOU                 |" << endl;
        cout << "+=======================================================================+" << endl;
        for (int i = 0; i < 7; i++) {
            cout << "                               " << (i + 1) << ". " << dunia_abyss[i].nama_dosa;
            if (dunia_abyss[i].boss_kalah) {
                cout << "    [BOSS DEFEATED]";
            }
            cout << endl;
        }
        cout << "                               8. EXIT" << endl;
        cout << "+=======================================================================+" << endl;
        cout << "|               The deeper you go, the stronger they are                |" << endl;
        cout << "+=======================================================================+" << endl;
        cout << "[Choose your desired stage]: ";
    
        int pilihan_stage = baca_int_aman();
        if (pilihan_stage == -999) {
            cout << "\n[Sistem]: Input tidak valid. Masukkan angka 1-8.\n";
            press_enter();
            continue;
        }
        if (pilihan_stage >= 1 && pilihan_stage <= 7) {
            masuk_stage_dosa(pilihan_stage - 1); 
        } else if (pilihan_stage == 8) {
            clear_screen();
            cout << "\nKeluar dari game. Sampai jumpa lagi, " << player.nama << "!\n";
            break;
        } else {
            cout << "\n[Sistem]: Pilihan tidak valid. Masukkan 1 sampai 8.\n";
            press_enter();
        }
    } 
    return 0;
}