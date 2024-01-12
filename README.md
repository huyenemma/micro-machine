# Micro Machine game

This game is a tribute to classic micro machine racing, utilizing Box2D for physics and SFML for graphics. It offers a mix of fun, challenge, and competitive spirit with both single and multiplayer modes.

### Installation Instructions:

1. **Install SFML on Your Computer:**
   - Visit the [SFML website](https://www.sfml-dev.org/download.php) and download the version compatible with your operating system.
   - Follow the installation guide provided on their website to properly set up SFML on your system.

2. **Clone the Game from Git**

3. **Set Up the Build Environment:**
   - Delete the existing build folder (if any) in the cloned directory.
   - Open your terminal or command prompt.
   - Navigate to the game's root directory.
   - Run the following commands:
     ```
     mkdir build         # Creates a new build folder
     cd build            # Changes the directory to the build folder
     cmake ..            # Runs the CMake file to configure the project
     make                # Compiles and builds the game
     ```

4. **Running the Game:**
   - Inside the build folder, execute `./MicroMachine` to start the game.

5. **For Subsequent Builds:**
   - If you make any changes to the game, or after the first build, start from step 3(d) (`make`) to rebuild and run the game.

### How to Play:

1. **Starting the Game:**
   - After building the game, a menu will appear.
   - Use the `Up` and `Down` arrow keys to choose between `One Player` and `Two Players` mode.
   - Press `Enter` to confirm your choice.

2. **Selecting a Map:**
   - Choose your desired map using the arrow keys.
   - Press `Enter` to start the game.

3. **Game Controls:**
   - Control your vehicle using the arrow keys (`Up`, `Left`, `Right`) for one player, and `W`, `A`, `D` keys for the second player in two-player mode.
   - Press `Enter` to activate your super skill.

4. **Objective and Time Limit:**
   - The objective is to complete 3 laps around the track before your opponent.
   - The game has a 15-minute time limit. The session will end automatically when the time is up.

### Credit

This project was developed as a group project of Aalto University ELEC-A7151 Object-oriented Programming with C++ course in 2023. The responsible teacher for the course was Yusein Ali, and the project advisor was Tuukka Himanka.

The project was developed by

- Huyen Do ([@huyenemma](https://github.com/huyenemma))
- Quan Hoang ([@qqUAnH](https://github.com/qqUAnH))
- Linh Nguyen 
- Duy To ([@Julian](https://github.com/ponyo19))
