# input tugas
tugas =  []
tugas.append("Belajar Python")
for i, t in enumerate(tugas):
    print(i+1, t)
while True:
    print("Mau ngapain?:")
    while True:
        print("1. Tambah tugas")
        print("2. Hapus tugas")
        print("3. Lihat tugas")
        print("4. Keluar")
        pilihan = input("Masukkan pilihan (1-4): ")
        if pilihan == "1":
            tugas_baru = input("Masukkan tugas baru: ")
            tugas.append(tugas_baru)
            print(f"Tugas '{tugas_baru}' berhasil ditambahkan.")
        elif pilihan == "2":
            if not tugas:
                print("Tidak ada tugas untuk dihapus.")
                continue
            for i, t in enumerate(tugas):
                print(i+1, t)
            index_hapus = int(input("Masukkan nomor tugas yang ingin dihapus: ")) - 1
            if 0 <= index_hapus < len(tugas):
                tugas_dihapus = tugas.pop(index_hapus)
                print(f"Tugas '{tugas_dihapus}' berhasil dihapus.")
            else:
                print("Nomor tugas tidak valid.")
        elif pilihan == "3":
            if not tugas:
                print("Tidak ada tugas.")
            else:
                for i, t in enumerate(tugas):
                    print(i+1, t)
        elif pilihan == "4":
            print("Keluar dari program.")
            break
        else:
            print("Pilihan tidak valid. Silakan coba lagi.")