#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Max voters and candidates
#define MAX_VOTERS 100
#define MAX_CANDIDATES 9
// Preferences: preferences[i][j] is the jth preference for voter i
int preferences[MAX_VOTERS][MAX_CANDIDATES];
// Candidate structure
typedef struct {
    char *name;
    int votes;
    bool eliminated;
} candidate;

// Array of candidates
candidate *candidates = NULL;
// Number of voters and candidates
int voter_count;
int candidate_count;
// Function prototypes
bool vote(int voter, int rank, const char *name);
void tabulate(void);
bool print_winner(void);
int find_min(void);
bool is_tie(int min);
void eliminate(int min);
void free_resources(void);
char* get_input(const char *prompt);

// Utility prototypes
bool is_valid_integer(const char *input);
void reset_votes(void);

// Main function
int main(int argc, char *argv[]) 
{
    // Check usage
    if (argc < 2) 
    {
        fprintf(stderr, "Usage: %s [candidate ...]\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Initialize candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX_CANDIDATES) 
    {
        fprintf(stderr, "Maximum number of candidates is %d.\n", MAX_CANDIDATES);
        return EXIT_FAILURE;
    }
    
    candidates = malloc(candidate_count * sizeof(candidate));
    if (!candidates) 
    {
        perror("Memory allocation failed");
        return EXIT_FAILURE;
    }

    for (int i = 0; i < candidate_count; i++) 
    {
        candidates[i].name = strdup(argv[i + 1]);
        candidates[i].votes = 0;
        candidates[i].eliminated = false;
    }

    // Get number of voters
    while (true) 
    {
        char *voter_input = get_input("Number of voters: ");
        if (is_valid_integer(voter_input)) 
        {
            voter_count = atoi(voter_input);
            free(voter_input);

            if (voter_count > 0 && voter_count <= MAX_VOTERS) {
                break;
            } else {
                printf("Please enter a number between 1 and %d.\n", MAX_VOTERS);
            }
        } 
        else 
        {
            printf("Invalid input. Please enter a valid integer.\n");
            free(voter_input);
        }
    }

    // Query votes
    for (int i = 0; i < voter_count; i++) 
    {
        printf("\nCollecting votes for Voter %d:\n", i + 1);
        for (int j = 0; j < candidate_count; j++) 
        {
            while (true) 
            {
                char prompt[50];
                snprintf(prompt, sizeof(prompt), "Rank %d: ", j + 1);
                char *name = get_input(prompt);

                if (vote(i, j, name)) 
                {
                    free(name);
                    break;
                }

                printf("Invalid vote. Please enter a valid candidate name.\n");
                free(name);
            }
        }
    }

    // Conduct runoff
    while (true) 
    {
        tabulate();

        if (print_winner()) 
        {
            break;
        }

        int min = find_min();
        if (is_tie(min)) 
        {
            printf("\nElection ends in a tie. The winners are:\n");
            for (int i = 0; i < candidate_count; i++) 
            {
                if (!candidates[i].eliminated) 
                {
                    printf("- %s\n", candidates[i].name);
                }
            }
            break;
        }

        eliminate(min);
        reset_votes();
    }

    free_resources();
    return EXIT_SUCCESS;
}

// Record preference if vote is valid
bool vote(int voter, int rank, const char *name) 
{
    for (int i = 0; i < candidate_count; i++) 
    {
        if (strcmp(name, candidates[i].name) == 0) 
        {
            preferences[voter][rank] = i;
            return true;
        }
    }
    return false;
}

// Tabulate votes for non-eliminated candidates
void tabulate(void) 
{
    for (int i = 0; i < voter_count; i++) 
    {
        for (int j = 0; j < candidate_count; j++) 
        {
            int candidate_index = preferences[i][j];
            if (!candidates[candidate_index].eliminated)
            {
                candidates[candidate_index].votes++;
                break;
            }
        }
    }
}

// Print the winner if there is one
bool print_winner(void) 
{
    for (int i = 0; i < candidate_count; i++) 
    {
        if (candidates[i].votes > voter_count / 2) 
        {
            printf("\nWinner: %s\n", candidates[i].name);
            return true;
        }
    }
    return false;
}

// Find the minimum number of votes for non-eliminated candidates
int find_min(void) 
{
    int min_votes = voter_count;
    for (int i = 0; i < candidate_count; i++) 
    {
        if (!candidates[i].eliminated && candidates[i].votes < min_votes) 
        {
            min_votes = candidates[i].votes;
        }
    }
    return min_votes;
}

// Check if there is a tie
bool is_tie(int min) 
{
    for (int i = 0; i < candidate_count; i++) 
    {
        if (!candidates[i].eliminated && candidates[i].votes != min) 
        {
            return false;
        }
    }
    return true;
}

// Eliminate candidates with the minimum number of votes
void eliminate(int min) 
{
    for (int i = 0; i < candidate_count; i++) 
    {
        if (!candidates[i].eliminated && candidates[i].votes == min)
        {
            candidates[i].eliminated = true;
        }
    }
}

// Reset vote counts to zero
void reset_votes(void) {
    for (int i = 0; i < candidate_count; i++) {
        candidates[i].votes = 0;
    }
}

// Free dynamically allocated resources
void free_resources(void)
 {
    if (candidates) 
    {
        for (int i = 0; i < candidate_count; i++) 
        {
            free(candidates[i].name);
        }
        free(candidates);
    }
}

// Get user input
char* get_input(const char *prompt)
 {
    printf("%s", prompt);
    char buffer[100];
    if (fgets(buffer, sizeof(buffer), stdin))
     {
        buffer[strcspn(buffer, "\n")] = '\0'; // Remove newline
        return strdup(buffer);
    }
    return NULL;
}

// Validate if a string represents a valid integer
bool is_valid_integer(const char *input)
 {
    for (int i = 0; input[i]; i++) 
    {
        if (input[i] < '0' || input[i] > '9')
        {
            return false;
        }
    }
    return true;
}
