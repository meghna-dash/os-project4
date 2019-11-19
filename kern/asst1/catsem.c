/*
 * catsem.c
 *
 * 30-1-2003 : GWA : Stub functions created for CS161 Asst1.
 *
 * NB: Please use SEMAPHORES to solve the cat syncronization problem in
 * this file.
 */


/*
 *
 * Includes
 *
 */

#include <types.h>
#include <lib.h>
#include <test.h>
#include <thread.h>


/*
 *
 * Constants
 *
 */

/*
 * Number of food bowls.
 */

#define NFOODBOWLS 2

/*
 * Number of cats.
 */

#define NCATS 6

/*
 * Number of mice.
 */

#define NMICE 2

/*
 * Create a semaphore.
 *
 * A semaphore is a variable shared between threads and
 * is used to achieve process synchronization by toggling,
 * incrementing, decrementing, etc.
 */
struct semaphore *resources;

/*
 * We first need an integer variable to track the status of
 * each food bowl. Since we have two food bowls, we will need
 * two such variables.
 *
 * We can simply track the status of the fool bowls using the
 * following schema (per bowl):
 *     0 - no animal at the bowl
 *     1 - a cat is at the bowl
 *     2 - a mouse is at the bowl
 */
 int bowl1 = 0;
 int bowl2 = 0;

/*
 * We need two arrays to track how much each cat and mouse
 * has eaten.
 *
 * There are 6 cats, so the cat array will have 6 elements.
 * There are 2 mice, so the mice array will have 2 elements.
 */
 int cats_iteration[6] = {0,0,0,0,0,0};
 int mice_iteration[2] = {0,0};

/*
 *
 * Function Definitions
 *
 */


/*
 * catsem()
 *
 * Arguments:
 *      void * unusedpointer: currently unused.
 *      unsigned long catnumber: holds the cat identifier from 0 to NCATS - 1.
 *
 * Returns:
 *      nothing.
 *
 * Notes:
 *      Write and comment this function using semaphores.
 *
 */

static
void
catsem(void * unusedpointer,
       unsigned long catnumber)
{
        /*
         * Avoid unused variable warnings.
         */

        (void) unusedpointer;
        (void) catnumber;
}


/*
 * mousesem()
 *
 * Arguments:
 *      void * unusedpointer: currently unused.
 *      unsigned long mousenumber: holds the mouse identifier from 0 to
 *              NMICE - 1.
 *
 * Returns:
 *      nothing.
 *
 * Notes:
 *      Write and comment this function using semaphores.
 *
 */

static
void
mousesem(void * unusedpointer,
         unsigned long mousenumber)
{
        /*
         * Avoid unused variable warnings.
         */

        (void) unusedpointer;
        (void) mousenumber;
}


/*
 * catmousesem()
 *
 * Arguments:
 *      int nargs: unused.
 *      char ** args: unused.
 *
 * Returns:
 *      0 on success.
 *
 * Notes:
 *      Driver code to start up catsem() and mousesem() threads.  Change this
 *      code as necessary for your solution.
 */

int
catmousesem(int nargs,
            char ** args)
{
        int index, error;

        /*
         * Avoid unused variable warnings.
         */

        (void) nargs;
        (void) args;

        /*
         * Start NCATS catsem() threads.
         */

        for (index = 0; index < NCATS; index++) {

                error = thread_fork("catsem Thread",
                                    NULL,
                                    index,
                                    catsem,
                                    NULL
                                    );

                /*
                 * panic() on error.
                 */

                if (error) {

                        panic("catsem: thread_fork failed: %s\n",
                              strerror(error)
                              );
                }
        }

        /*
         * Start NMICE mousesem() threads.
         */

        for (index = 0; index < NMICE; index++) {

                error = thread_fork("mousesem Thread",
                                    NULL,
                                    index,
                                    mousesem,
                                    NULL
                                    );

                /*
                 * panic() on error.
                 */

                if (error) {

                        panic("mousesem: thread_fork failed: %s\n",
                              strerror(error)
                              );
                }
        }

        return 0;
}


/*
 * End of catsem.c
 */
