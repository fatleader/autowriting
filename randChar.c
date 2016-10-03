#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

//#define MIN 32
//#define MAX 127

#define MIN 96
#define MAX 123

// fn prototypes
void write(FILE *fp);
void compare(FILE *shit, FILE *eng, int *end);
unsigned int rand_interval(unsigned int min, unsigned int max);


/*
le main function.
ideally we get it to write then read and sort
*/

int main ()
{

  // the evidence
  FILE *fp;
  int end;
  // prompt
  printf("Enter how many chars u want bby: ");
  scanf("%d", &end);

  // call write.
  write(fp, end);

}

void compare (FILE *shit, FILE *eng, int *end){
  //where we store the string from
  char *lineShit = NULL, *lineEng = NULL;
  size_t lenShit = 0, lenEng = 0;

  ssize_t readShit, readEng;

  if((shit=fopen("text", "rb")==NULL)||(eng=fopen("english", "rb"))){
    perror("Invalid file path");
  }

  while ((readShit = getline(&lineShit, &lenShit, shit)) != -1 &&
    (readEng = getline(&lineEng, &lenEng, eng)) != -1){
      if ()
    }

}

/*
write some chars
takes in a file struct
*/

void write(FILE *fp, int *end){

  // this is what we actually write.
  unsigned int write;
  int wLimit = rand_interval(3,27), count = 0, wcCount = 0, end;

  while (count<end)
  {
    // call random function
    write = rand_interval(MIN, MAX);

    // for null byte.
    if (write == 10){
      if ((fp = fopen("text", "ab+"))==NULL){
        // whoopsies! no path found!
        perror("Invalid file path!");
      } else{
        // no error, write to file!
        fputc(write, fp);
        fclose (fp);
        // we back out of if to while. hopefully rand_interval runs?
        // pardon muh'logic
        wcCount = 0;
        wLimit = rand_interval(3,27);
        write = rand_interval(MIN, MAX);
        count += 1;
        //break;
      }
    }

    // just for lowercase letters.
    if ((write>96)&&(write<123)){

      //printf("wCCount: %i", wcCount);
      //printf("wLimit: %i", wLimit);

      if ((fp = fopen("text", "ab+"))==NULL){
        // whoopsies! no path found!
        perror("Invalid file path!");
      }
      else{
        // largest shakespeare word is 27 letters: long 'nough for me.
        if (wcCount < wLimit){
        // now we continue, write character.
        fputc(write, fp);
        // we back out of if to while. hopefully rand_interval runs?
        // pardon muh'logic
        wcCount += 1;
        count += 1;
        }
        else {
        // write new line, reset counter, limit.
        fputc(10, fp);
        wLimit = rand_interval(3,27);
        wcCount = 0;
        }
      }
    }
    else{
      // nice try no cigar
      write = rand_interval(MIN, MAX);
    }
    fclose (fp);
}

}

/*
a researched solution to c's bounded random generator. cannot just use %
since makes assumption about c's rand generator.
 */
unsigned int rand_interval(unsigned int min, unsigned int max)
{
  int r;
  const unsigned int range = 1 + max - min;
  const unsigned int buckets = RAND_MAX / range;
  const unsigned int limit = buckets * range;

  /* Create buckets, fire randomly at buckets till you land.
   * If you don't land, try again.
   */

   do
   {
     r = rand();
   } while(r >= limit);

   return min + (r/buckets);
}
