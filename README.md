# GameOfLife

## Description
GameOfLife is an implementation of Conway’s Game of Life, a zero-player cellular automaton that evolves over discrete time steps based on a set of simple rules. The project demonstrates grid-based state management and rule-driven simulation logic, making it a useful reference for understanding algorithmic state transitions and visual simulations.

## Badges
![Repo Size](https://img.shields.io/github/repo-size/drussell33/GameOfLife)
![Last Commit](https://img.shields.io/github/last-commit/drussell33/GameOfLife)
![Top Language](https://img.shields.io/github/languages/top/drussell33/GameOfLife)

## Key Features
- Grid-based simulation of Conway’s Game of Life
- Iterative state updates based on defined neighbor rules
- Visualization of cell states across generations
- Encapsulated logic for rule evaluation and state transitions

## Tech Stack
### Backend
- .NET (C#)

### Frontend
- Native UI (if applicable) or console-based rendering

### Database
- None

### Tools / Services
- Visual Studio
- Git

## Architecture Overview
The application is structured around a simulation engine that manages a two-dimensional grid of cells. Each cell's state is updated based on the number of live neighbors, following Conway’s rules. 

Core responsibilities are typically separated into:
- **Grid/Board Model**: Represents the current state of the simulation
- **Simulation Logic**: Applies rules to compute the next generation
- **Rendering Layer**: Displays the grid state (UI or console)

The system follows a clear separation of concerns where state management and rendering are decoupled, allowing the simulation logic to remain testable and extensible.

## Project Structure
```bash
GameOfLife/
├── GameOfLife.sln
├── GameOfLife/
│   ├── Program.cs
│   ├── Models/
│   ├── Services/
│   ├── UI/ (if applicable)
│   └── ...
```

- **Models/**: Contains core data structures such as the grid or cell representation
- **Services/**: Contains simulation logic and rule processing
- **UI/**: Responsible for rendering output (if applicable)

## Getting Started

### Prerequisites
- .NET SDK
- Visual Studio or compatible IDE

### Installation
```bash
git clone https://github.com/drussell33/GameOfLife.git
cd GameOfLife
```

### Usage
```bash
dotnet build
dotnet run
```

## Roadmap
- [x] Core Game of Life simulation logic
- [x] Grid-based state representation
- [ ] Add interactive controls (start/stop/reset)
- [ ] Improve visualization (UI enhancements)
- [ ] Add configurable grid size and rules
- [ ] Implement performance optimizations for large grids

## Contributing
Contributions are welcome. Please follow standard GitHub workflow:

1. Fork the repository
2. Create a feature branch
3. Commit your changes
4. Push to your fork
5. Open a Pull Request

## Screenshots / Demo
_Add screenshots or demo GIFs here_

## Contact
GitHub: https://github.com/drussell33
