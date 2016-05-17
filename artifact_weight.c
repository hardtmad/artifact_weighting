/* An implementation of artifact weighting */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define artifact weights
#define prog_w 10
#define midterm_w 20
#define take_home_w 5
#define fuka_w 10
#define research_w 10
#define poster_w 5
#define final_w 40

// Calculate final grade point given grades on all assignments
float grade_eval(float prog_art,
                     float midterm_art,
                     float take_home_art,
                     float fuka_art,
                     float research_art,
                     float poster_art,
               float final_art);

// Calculate grade point so far given grades on the first four assignments 
float partial_grade_eval(float prog_art,
                         float midterm_art,
                         float take_home_art,
                         float fuka_art);

// Calculate what grades are needed on final three assignments to maintain A grade point
void calculate_maintenance(float grade);

int main() {
  // Ask user whether we are calculating final or partial grade point 
  printf("Enter \"a\" if you have all grades and \"p\" if you want to determine what you need on the final to get an A in the class: \n");
  char type;
  scanf("%c", &type);

  float prog_art;
  float midterm_art;
  float take_home_art;
  float fuka_art;
  float research_art;
  float poster_art;
  float final_art;
  float grade;

  // Prompt user for all grades
  if (type == 'a'){
    printf("Program grade (1-5): \n");
    scanf("%f", &prog_art);
    printf("Midterm grade (1-5): \n");
    scanf("%f", &midterm_art);
    printf("Take home grade (1-5): \n");
    scanf("%f", &take_home_art);
    printf("Fuka grade (1-5): \n");
    scanf("%f", &fuka_art);
    printf("Research grade (1-5): \n");
    scanf("%f", &research_art);
    printf("Poster grade (1-5): \n");
    scanf("%f", &poster_art);
    printf("Final grade (1-5): \n");
    scanf("%f", &final_art);
    // Evaluate final grade point
    grade = grade_eval(prog_art, midterm_art, take_home_art, fuka_art, research_art, poster_art, final_art);
    printf("Final grade point: %.2f\n", grade);
  }
  // Prompt user for grade so far
  else if (type == 'p'){
    printf("Program grade (1-5): \n");
    scanf("%f", &prog_art);
    printf("Midterm grade (1-5): \n");
    scanf("%f", &midterm_art);
    printf("Take home grade (1-5): \n");
    scanf("%f", &take_home_art);
    printf("Fuka grade (1-5): \n");
    scanf("%f", &fuka_art);
    // Evaluate grade point so far 
    grade = partial_grade_eval(prog_art, midterm_art, take_home_art, fuka_art);
    printf("Grade point so far: %.2f\n", grade);
    calculate_maintenance(grade);
  }

  else
    printf("Invalid command.");
  
  return 0;
}

// Calculate final grade point given grades on all assignments
float grade_eval(float prog_art, float midterm_art, float take_home_art, float fuka_art, float research_art, float poster_art, float final_art) {
  float prog = prog_art * prog_w;
  float midterm = midterm_art * midterm_w;
  float take_home = take_home_art *take_home_w;
  float fuka = fuka_art * fuka_w;
  float research = research_art * research_w;
  float poster = poster_art * poster_w;
  float final = final_art * final_w;
  float grade = (prog + midterm + take_home + fuka + research + poster + final)/100;
  return grade;
}

// Calculate grade point so far given grades on the first four assignments 
float partial_grade_eval(float prog_art, float midterm_art, float take_home_art, float fuka_art) {
  float prog = prog_art * prog_w;
  float midterm = midterm_art * midterm_w;
  float take_home = take_home_art *take_home_w;
  float fuka = fuka_art * fuka_w;
  float grade = (prog + midterm + take_home + fuka)/45;
  return grade;
}

// Calculate what grades are needed on final three assignments to maintain A grade point
void calculate_maintenance(float grade){
  // Calculate total points needed to get an A
  float points_needed = 450 - (grade * 45);\
  // Calculate average grade needed on each problem to maintain an A
  float research_grade = (points_needed * 10 / 55) / research_w;
  float poster_grade = (points_needed * 5 / 55) /poster_w;
  float final_grade = (points_needed * 40 / 55) / final_w;
  printf("You need approximately %.2f on all remaining assignments to maintain an A.\n", research_grade);

  final_grade = (points_needed - (research_w * 5) - (poster_w * 5)) / final_w;
  printf("\nIf you receive a 5 on the research and the poster, you need approximately %.2f on all final exam questions to maintain an A.\n", final_grade);
}
