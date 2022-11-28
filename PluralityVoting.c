#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

typedef struct
{
    string name;
    int votes;
}
candidate;

// Array of candidates
candidate candidates[MAX];

// Number of candidates
int candidate_count;

// Function prototypes
bool vote(string name);
void swap(candidate *a, candidate *b);
void print_winner(void);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: plurality [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
    }

    int voter_count = get_int("Number of voters: ");

    // Loop over all voters
    //? this skips the vote if invalid
    for (int i = 0; i < voter_count; i++)
    {
        string name = get_string("Vote: ");

        // Check for invalid vote
        if (!vote(name))
        {
            printf("Invalid vote.\n");
        }
    }

    // Display winner of election
    print_winner();

}

// Update vote totals given a new vote
bool vote(string name)
{
    int result;
    // TODO
    for (int i = 0; i < candidate_count; i ++)
    {
        result = strcmp(name, candidates[i].name);
        if (result == 0)
        {
            candidates[i].votes ++;
            return true;
        }
    }
    return false;
}

// Print the winner (or winners) of the election
void print_winner(void)
{
    // nice likkle selection sort of candidates
    int n = candidate_count;
    int minIndex;

    for (int i = 0; i < n - 1; i ++)
    {
        minIndex = i;
        for (int j = i + 1; j < n; j ++)
        {
            if (candidates[j].votes < candidates[minIndex].votes)
            {
                minIndex = j;
            }
        }
        swap(&candidates[minIndex], &candidates[i]);
    }
    // ... thank god for white boards...

    // check highest candidate is higher than the one before it

    if (candidates[n - 1].votes > candidates[n - 2].votes)
    {
        printf("%s", candidates[n - 1].name);
        printf("\n");
    }

    else if (candidates[n - 1].votes == candidates[n - 2].votes)
    {
        printf("%s\n", candidates[n - 1].name);

        for (int i = 0; i < n - 1; i++)
        {
            if (candidates[i].votes == candidates[n - 1].votes)
            {
                printf("%s\n", candidates[i].name);
            }
        }
    }
}

void swap(candidate *a, candidate *b)
{
    candidate temp = *a;
    *a = *b;
    *b = temp;
}
