# Beomff: Visual Novel in Allegro5

![beom-proto](https://github.com/user-attachments/assets/bde975a1-c02e-4f64-8866-d78e72abaeae)


Beomff is a visual novel developed in C using the Allegro 5 game development library. The story explores themes of tyranny, quantum physics, and year 2000 cellphone aesthetics. 

## Features
- **Immersive Storytelling**: Dive into a narrative that combines dystopian themes and speculative science.
- **Retro Aesthetic**: Emulates the charm of early 2000s cellphone interfaces.
- **Interactive Gameplay**: Navigate through choices that shape the story's outcome.

## Requirements
- C compiler (e.g., `clang`)
- Allegro 5 libraries
- SQLite3 library

## Build Instructions
To build the project, ensure all required libraries are installed, then use the following command:

```sh
clang *.c -o beomff -lsqlite3 -lallegro -lallegro_image -lallegro_font -lallegro_ttf -lallegro_primitives -lallegro_audio -lallegro_acodec
```

## How to Run
After building the project, run the executable:

```sh
./beomff
```

## License
This project is licensed under the MIT License. See the `LICENSE` file for details.

---

Enjoy exploring the story of Beomff!

