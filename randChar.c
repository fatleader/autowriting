#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

#define MIN 32
#define MAX 127

int main ()
{
  // this is the unsigned int we are converting ascii
  unsigned int convert;
  // this is what we actually write.
  char write;
  // the evidence
  FILE *fp;
  // run forever...
  while (1)
  {
    // call random function
    convert = rand_interval(MIN, MAX);
    // now we sift through the shit
    // i've omitted the comments to make things more fun

    if (convert == 32){
      write = convert;
      if ((fp = fopen("path/to/file", "w+"))==NULL){
        // whoopsies! no path found!
        perror("Invalid file path!");
      } else{
        // no error, write to file!
        fputs(write, fp);
        fclose (fp);
        // we back out of if to while. hopefully rand_interval runs?
        // pardon muh'logic
        break;
      }
    }
    else if (convert == 33){
      write = convert;
      if ((fp = fopen("path/to/file", "w+"))==NULL){
        // whoopsies! no path found!
        perror("Invalid file path!");
      } else{
        // no error, write to file!
        fputs(write, fp);
        fclose (fp);
        // we back out of if to while. hopefully rand_interval runs?
        // pardon muh'logic
        break;
      }
    }
    else if (convert == 46){
      write = convert;
      if ((fp = fopen("path/to/file", "w+"))==NULL){
        // whoopsies! no path found!
        perror("Invalid file path!");
      } else{
        // no error, write to file!
        fputs(write, fp);
        fclose (fp);
        // we back out of if to while. hopefully rand_interval runs?
        // pardon muh'logic
        break;
      }
    }
    else if (convert == 63){
      write = convert;
      if ((fp = fopen("path/to/file", "w+"))==NULL){
        // whoopsies! no path found!
        perror("Invalid file path!");
      } else{
        // no error, write to file!
        fputs(write, fp);
        fclose (fp);
        // we back out of if to while. hopefully rand_interval runs?
        // pardon muh'logic
        break;
      }
    }
    else if ((convert>64)&&(convert<91)){
      write = convert;
      if ((fp = fopen("path/to/file", "w+"))==NULL){
        // whoopsies! no path found!
        perror("Invalid file path!");
      } else{
        // no error, write to file!
        fputs(write, fp);
        fclose (fp);
        // we back out of if to while. hopefully rand_interval runs?
        // pardon muh'logic
        break;
      }
    }
    else if ((convert>96)&&(convert<123)){
      write = convert;
      if ((fp = fopen("path/to/file", "w+"))==NULL){
        // whoopsies! no path found!
        perror("Invalid file path!");
      } else{
        // no error, write to file!
        fputs(write, fp);
        fclose (fp);
        // we back out of if to while. hopefully rand_interval runs?
        // pardon muh'logic
        break;
      }
    }
    else {
      // nice try no cigar
      convert = rand_interval(MIN, MAX);
    }
  }

}

/*
 * a researched solution to c's bounded random generator. cannot just use %
 * since makes assumption about c's rand generator.
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
