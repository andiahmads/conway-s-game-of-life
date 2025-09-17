# conway-s-game-of-life
Conway's Game of Life adalah sebuah cellular automaton yang diciptakan oleh John Horton Conway, 
seorang matematikawan asal Inggris, pada tahun 1970. 
Game ini terkenal karena menunjukkan bagaimana aturan yang sangat sederhana bisa menghasilkan pola yang kompleks dan bahkan tampak seperti memiliki “kehidupan” sendiri.
Conway's Game of Life hingga kini dipandang sebagai contoh klasik dari emergent complexity — di mana aturan sederhana bisa menghasilkan sistem yang kompleks.
Ia juga menginspirasi perkembangan dalam bidang:
- Teori chaos dan kompleksitas
- Simulasi biologi dan ekosistem
- Pemrograman grafis dan AI
- Seni generatif dan algoritma kreatif

# aturan game
| Kondisi Sel Saat Ini | Jumlah Tetangga Hidup | Keadaan Berikutnya | Penjelasan                                                                            |
| -------------------- | --------------------- | ------------------ | ------------------------------------------------------------------------------------- |
| 🟩 Hidup             | < 2                   | ⬜ Mati             | **Kesepian (Underpopulation)** — Sel mati karena terlalu sedikit tetangga.            |
| 🟩 Hidup             | 2 atau 3              | 🟩 Tetap Hidup     | **Stabilitas (Survival)** — Sel tetap hidup karena kondisi seimbang.                  |
| 🟩 Hidup             | > 3                   | ⬜ Mati             | **Overpopulasi (Overpopulation)** — Sel mati karena terlalu banyak tetangga.          |
| ⬜ Mati               | = 3                   | 🟩 Hidup           | **Kelahiran (Reproduction)** — Sel mati menjadi hidup jika tepat tiga tetangga hidup. |


## Getting Started

Run:

```console
brew install raylib
```

## on linux

Read:

```
https://github.com/raysan5/raylib/discussions/2673
```

## Compile

Run:

```console
make
```
