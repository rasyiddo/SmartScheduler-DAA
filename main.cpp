#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Struktur untuk menyimpan data setiap job
struct Job {
    string id;        // Nama atau ID job (misalnya: "A", "B", "C")
    int processing;   // Waktu proses (processing time)
    int deadline;     // Deadline job (dalam satuan waktu)
    int completion;   // Waktu selesai job (akan dihitung kemudian)
};

// Fungsi utama untuk algoritma Earliest Deadline First (EDF)
bool sortByDeadline(const Job &a, const Job &b) {
    return a.deadline < b.deadline; // Urutkan berdasarkan deadline yang paling awal
}

int main() {
    // ------------------------------------------------------------
    // 1️. Inisialisasi data sesuai contoh di report.docx
    // ------------------------------------------------------------
    vector<Job> jobs = {
        {"A", 3, 5, 0},   // Job A butuh waktu proses 3, deadline = 5
        {"B", 2, 7, 0},   // Job B butuh waktu proses 2, deadline = 7
        {"C", 1, 4, 0}    // Job C butuh waktu proses 1, deadline = 4
    };

    // ------------------------------------------------------------
    // 2️. Urutkan job berdasarkan deadline menggunakan Greedy EDF
    // ------------------------------------------------------------
    sort(jobs.begin(), jobs.end(), sortByDeadline);

    // ------------------------------------------------------------
    // 3️. Proses setiap job sesuai urutan deadline
    //    Hitung waktu selesai dan jumlah job yang tepat waktu
    // ------------------------------------------------------------
    int currentTime = 0;
    int onTimeJobs = 0;

    cout << "=== SmartScheduler: Saving Time in the Cloud ===\n";
    cout <<"=== Mid Test DAA===\n\n";
    cout << "Urutan eksekusi (berdasarkan Earliest Deadline First):\n";

    for (auto &job : jobs) {
        currentTime += job.processing;   // Tambah waktu proses job ini
        job.completion = currentTime;    // Simpan waktu selesai
        cout << "Job " << job.id
             << " | Waktu Proses: " << job.processing
             << " | Deadline: " << job.deadline
             << " | Selesai: " << job.completion;

        if (job.completion <= job.deadline) {
            cout << " ✅ (Tepat Waktu)\n";
            onTimeJobs++;
        } else {
            cout << " ❌ (Terlambat)\n";
        }
    }

    // ------------------------------------------------------------
    // 4️. Hitung dan tampilkan persentase job yang selesai tepat waktu
    // ------------------------------------------------------------
    double percentage = (double)onTimeJobs / jobs.size() * 100.0;

    cout << "\nTotal Job: " << jobs.size() << endl;
    cout << "Job Tepat Waktu: " << onTimeJobs << endl;
    cout << "Persentase Tepat Waktu: " << percentage << "%\n";
    cout << "\nTotal Waktu Penyelesaian: " << currentTime << " unit waktu\n";

    return 0;
}
