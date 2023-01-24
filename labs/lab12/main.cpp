/*
 created by Daniel Kusai
*/

#include "InvalidMoveException.h"
#include <iostream>

const int RPS_SIZE = 3;
enum
{
    ROCK,
    PAPER,
    SCISSORS
};

void
check_winner(short cpu, short plr, int& cpu_wins, int& plr_wins);

int
main(void)
{
    short cpu_num = -1;
    char plr_chr = -1;
    short plr_num = -1;

    int cpu_wins = 0;
    int plr_wins = 0;
    while (true) {
        cpu_num = rand() % RPS_SIZE;
        std::cout << "Please choose a number less than " << RPS_SIZE
                  << std::endl;
        try {
            std::cin >> plr_chr;
            if (plr_chr < '0' || plr_chr > '9') {
                throw InvalidMoveException("error: not a number\n");
            }
            plr_num = plr_chr - '0';
            if (plr_chr > '2') {
                throw int(plr_num);
            }

            check_winner(cpu_num, plr_num, cpu_wins, plr_wins);
        } catch (const InvalidMoveException e) {
            std::cout << "error: " << e.message << std::endl;
        } catch (int num) {
            std::cout << "error: " << num << std::endl;
        } catch (char winner) {
            std::cout << "winner: " << winner << std::endl;
            break;
        } catch (long num) {
        }
    }

    return 0;
}

void
check_winner(short cpu, short plr, int& cpu_wins, int& plr_wins)
{
    const int DRAW = 0;
    const int CPU_WON = 1;
    const int PLAYER_WON = 2;

    short winner = (cpu - plr + 3) % 3;

    // std::cout << cpu << " " << plr << std::endl;
    // std::cout << "winner: " << winner << std::endl;

    if (winner == CPU_WON) {
        cpu_wins++;
    } else if (winner == PLAYER_WON) {
        plr_wins++;
    } else if (winner == DRAW) {
    } else
        exit(3);

    if (cpu_wins == 10)
        throw char('c');
    if (plr_wins == 10)
        throw char('p');
}