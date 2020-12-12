#include "snake.h"
#include "snake_map.h"
#include <pthread.h>
#include <iostream>
#include <vector>
#include <utility>
#include "snake_map.h"
#include "macros.h"
#include "intro.h"
#include <unistd.h>

using namespace std;

void *intro_thread_work(void *arg)
{
//    struct Snake *snake = (struct Snake *)arg;
		struct Intro *intro = (struct Intro *)arg;
    while (true)
    {
        enum Direction direction = get_input();
//        snake->update_next_direction(direction);
				intro->Update_Next_Direction(direction);
    }
}




void gotoxy(int x, int y) {
	printf("\033[%d;%df", y, x);
	fflush(stdout);
}


Intro::Intro(Snake snake) {
	this->snake = snake;
	sem_init(&intro_sema, 0, 2);
  pthread_create(&intro_thread, NULL, intro_thread_work, this);
}


void Intro::DrawIntro() {
//	for(int i = 0; i < MAP_END; i++)
//		cout << endl;
	system("clear");

	std::string init_intro_map[INTRO_HEIGHT] = 
	{"-----------------------------------------------------------------------------------",
	 "-                                                                                 -",
	 "-                                                  XXXXXXXXXXXX                   -",
	 "-          *********************                 XXXXX(>)XXXX(<)XX                -",
	 "-          *  SNAKE PSST !!!!  *                XXXXXXXXXXXXXXXXXX                -",
	 "-          *********************                XXXXXXXXXXXXX----------<          -",
	 "-                                                XXXXXXXXXXXXXX                   -",
	 "-                                              XXXXXXXXXXXX                       -",
	 "-              GAME  START                 XXXXXXXXXXXXX                          -",  
	 "-              RANK                      XXXXXXXXXXXXX                            -",
	 "-              EXIT                    XXXXXXXXXXXX                               -",
	 "-                                     XXXXXXXXXXXX                                -",
	 "-                                      XXXXXXXXXXXXXXXX                           -",
	 "-                                         XXXXXXXXXXXXXX                          -",
	 "-                     I                       XXXXXXXXXXXXX                       -",
	 "-                   III                           XXXXXXXXXXXX                    -",
	 "-                  IIII                               XXXXXXXXXX                  -",
	 "-                  IIII                                  XXXXXXXX                 -",
	 "-                  IIII                                 XXXXXXXXX                 -",
	 "-                  XXXXX                              XXXXXXXXXXX                 -",
	 "-                   XXXXX                         XXXXXXXXXXXXX                   -",
	 "-                   XXXXXXX                    XXXXXXXXXXXXX                      -",
	 "-                      XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX                            -",
	 "-                           XXXXXXXXXXXXXXXXXXXXXX                                -",
	 "-                                XXXXXXXXXXXXX                                    -",
	 "-                                                                                 -",
	 "-  Designed by YONG & SONG & YOUNG                                                -",
	 "-----------------------------------------------------------------------------------"};

	for(int i = 0; i < INTRO_HEIGHT; i++)
		this->intro_map[i] = init_intro_map[i];
}

void Intro::DrawUserCursor(int num) {
	switch (num) 
	{
		case 1:
			this->intro_map[8][13] = '>';
			break;
		case 2:
			this->intro_map[9][13] = '>';
			break;
		case 3:
			this->intro_map[10][13] = '>';
			break;
		default:
			break;
	}
	for(int i = 0; i < INTRO_HEIGHT; i++) {
		std::cout << this->intro_map[i] << std::endl;
	}
}

int Intro::SelectMenu() {
	int num = 1;
	int input = 0;
	while (true)
	{
		DrawIntro();
		DrawUserCursor(num);
		input = Get_Direction();
		printf("input : %d\n direction : %d\n", input,this->direction);
//		if (input == Space)
		if(input == Space)
		{
			switch (num)
			{
				case 1:
					return 1;	//PLAYER2
				case 2:
					return 2;	//RANK
				case 3:
					return 3;	//QUIT
			}
		}
		else { 
			switch (input)
			{
				case North:
					num--;
					if (num < 1) num = 3;
					break;
				case South:
					num++;
					if (num > 3) num = 1;
					break;
				default:
					break;
			}
		}
		usleep(PAUSE_LENGTH/2);
//		this->direction = Error;
		printf("before %d\n", this->next_direction);
		Validate_Direction();
		printf("after %d\n", this->direction);
	}
}

void Intro::Update_Direction(enum Direction direction)
{
    sem_wait(&this->intro_sema);
		printf("updating %d\n", direction);
    switch (direction)
    {
    case North:
        this->direction = direction;
        break;
    case South:
        this->direction = direction;
        break;
		case Space: 
				this->direction = direction;
				break;
		default:
				this->direction = Error;
				break;
    }
		printf("direction : %d\n", this->direction);
    sem_post(&this->intro_sema);
}

void Intro::Update_Next_Direction(enum Direction direction)
{
//		if (direction == North || direction == South) {
			this->next_direction = direction;
//		}
		printf("next direction : %d\n", this->next_direction);
}

enum Direction Intro::Get_Direction(void)
{
    enum Direction result = Error;
    sem_wait(&this->intro_sema);
    result = this->direction;
		this->direction = Error;
		this->next_direction = Error;
    sem_post(&this->intro_sema);
		printf("result : %d\n", result);
    return result;
}

void Intro::Validate_Direction(void)
{
//    if (next_direction != Error)
//    {
				printf("validate %d\n", this->next_direction);
        Update_Direction(this->next_direction);
//    }
}

