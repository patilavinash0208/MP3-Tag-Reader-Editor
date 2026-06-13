<div align="center">

# 🎵 MP3 Tag Reader & Editor

**A powerful command-line tool to read and modify MP3 metadata, built in C.**

![C](https://img.shields.io/badge/Language-C-blue?style=for-the-badge&logo=c)
![Platform](https://img.shields.io/badge/Platform-Linux%20%7C%20macOS-lightgrey?style=for-the-badge)
![License](https://img.shields.io/badge/License-MIT-green?style=for-the-badge)
![Status](https://img.shields.io/badge/Status-Active-brightgreen?style=for-the-badge)

</div>

---

## 📖 Overview

**MP3 Tag Reader & Editor** is a command-line application developed in **C** that allows users to view and modify metadata stored inside MP3 files. The application works with **ID3 tags** and provides functionality to read and update information such as song title, artist name, album name, genre, year, and comments.

> 🎯 Built as a systems programming project to explore file handling, binary processing, and metadata manipulation in C.

---

## ✨ Features

- 🔍 **View MP3 Metadata** — Display all ID3 tag fields at a glance
- ✏️ **Edit MP3 Metadata** — Modify any tag field directly from the terminal
- 🎵 **Read ID3 Tags** — Parse and extract embedded song information
- 🏷️ **Modify Song Title** — Update the track name
- 👤 **Modify Artist Name** — Change the artist/performer field
- 💿 **Modify Album Name** — Edit the album title
- 📅 **Modify Year** — Update the release year
- 🎸 **Modify Genre** — Change the music genre
- 💬 **Modify Comments** — Add or edit inline comments
- ✅ **MP3 File Validation** — Ensure the file is a valid MP3 before processing
- 🖥️ **Clean CLI Interface** — Simple and intuitive command-line experience

---

## 🛠️ Technologies Used

| Technology | Purpose |
|---|---|
| **C Programming** | Core application logic |
| **File Handling** | Open, read, and write MP3 files |
| **Binary File Processing** | Parse raw bytes of ID3 tag data |
| **String Manipulation** | Extract and format metadata fields |
| **Command Line Arguments** | Parse user input via `argc`/`argv` |

---

## 📁 Project Structure

```
mp3-tag-editor/
│
├── 📄 main.c         # Entry point; argument parsing and flow control
├── 📄 view.c         # Metadata display logic
├── 📄 view.h         # Header for view module
├── 📄 edit.c         # Tag editing and file write-back logic
├── 📄 help.c         # Help menu display
├── 📄 types.h        # Shared type definitions and structs
└── 📄 README.md      # Project documentation
```

---

## ⚙️ Compilation

Make sure you have **GCC** installed, then compile all source files with:

```bash
gcc *.c -o mp3_editor
```

---

## 🚀 Usage

### 👁️ View MP3 Metadata

```bash
./mp3_editor -v song.mp3
```

### ✏️ Edit a Specific Tag

| Flag | Field | Example |
|------|-------|---------|
| `-t` | Title | `./mp3_editor -e -t "New Song Name" song.mp3` |
| `-a` | Artist | `./mp3_editor -e -a "Artist Name" song.mp3` |
| `-A` | Album | `./mp3_editor -e -A "Album Name" song.mp3` |
| `-y` | Year | `./mp3_editor -e -y "2025" song.mp3` |
| `-g` | Genre | `./mp3_editor -e -g "Rock" song.mp3` |
| `-c` | Comment | `./mp3_editor -e -c "My comment" song.mp3` |

### ❓ Help Menu

```bash
./mp3_editor -h
```

---

## 📸 Sample Output

### 🔍 Viewing Metadata

```
----------------------------------
  MP3 TAG READER AND EDITOR
----------------------------------
Title   : Example Song
Artist  : Example Artist
Album   : Example Album
Year    : 2025
Genre   : Pop
----------------------------------
```

### ✅ Editing Metadata

```
File validation successful
Valid tag found
Tag updated successfully
```

---

## ⚙️ How It Works

```
1. 📂  Validate MP3 file format
        ↓
2. 🔍  Read ID3 metadata frames from binary
        ↓
3. 📤  Extract required tag information
        ↓
4. 🖥️  Display tag data to the user
        ↓
5. 🖊️  Modify selected tag (if -e flag used)
        ↓
6. 💾  Write updated metadata back to MP3 file
```

---

## 📚 Learning Outcomes

Through this project, hands-on experience was gained in:

- 📂 **File Handling in C** — Using `fopen`, `fread`, `fwrite`, `fseek`
- 🔢 **Binary File Processing** — Reading raw bytes and interpreting structured data
- 🏷️ **Metadata Parsing** — Understanding ID3v2 tag structure and frame layout
- 🔤 **String Manipulation** — Safe copying, formatting, and bounds checking
- 🖥️ **Command Line Argument Processing** — `argc`/`argv` parsing with `getopt`
- 🧩 **Modular Programming** — Splitting logic across `.c`/`.h` files
- 🐛 **Debugging and Testing** — Using `gdb` and systematic test cases

---

## 🔮 Future Enhancements

- [ ] 🆕 Support for **ID3v2.4** tags
- [ ] 📦 **Batch editing** of multiple MP3 files at once
- [ ] 🎶 **Playlist management** support
- [ ] 🖼️ **Album artwork** extraction and embedding
- [ ] 🖱️ **GUI version** using GTK or Qt

---

## 👨‍💻 Author

<div align="center">

**Avinash Patil**

[![GitHub](https://img.shields.io/badge/GitHub-patilavinash0208-181717?style=for-the-badge&logo=github)](https://github.com/patilavinash0208)
[![LinkedIn](https://img.shields.io/badge/LinkedIn-Avinash%20Patil-0A66C2?style=for-the-badge&logo=linkedin)](https://www.linkedin.com/in/avinash-patil-873b9b227)

</div>

---

<div align="center">

⭐ If you found this project helpful, please consider giving it a star!

</div>
