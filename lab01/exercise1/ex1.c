#include "ex1.h"

#include <string.h>

/* Returns the number of times LETTER appears in STR.
There are two different ways to iterate through a string.
1st way hint: strlen() may be useful
2nd way hint: all strings end in a null terminator */
int num_occurrences(char *str, char letter) {
  /* TODO: implement num_occurances */
  int count = 0;
  for (int i = 0; i < (int)strlen(str); i++) {  // NOLINT
    if (letter == *(str + i)) {
      count += 1;
    }
  }

  return count;
}

/* Populates DNA_SEQ with the number of times each nucleotide appears.
Each sequence will end with a NULL terminator and will have up to 20
nucleotides. All letters will be upper case. */
void compute_nucleotide_occurrences(DNA_sequence *dna_seq) {
  /* TODO: implement compute_nucleotide_occurances */
  memset(&dna_seq->A_count, 0, sizeof(int) * 4);
  char *seq = dna_seq->sequence;
  while (*seq) {
    switch (*seq) {
      case 'A':
        dna_seq->A_count++;
        break;
      case 'C':
        dna_seq->C_count++;
        break;
      case 'G':
        dna_seq->G_count++;
        break;
      case 'T':
        dna_seq->T_count++;
        break;

      default:
        break;
    }
    seq++;
  }
  return;
}
