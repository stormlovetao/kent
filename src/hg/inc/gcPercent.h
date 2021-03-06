/* gcPercent.h was originally generated by the autoSql program, which also 
 * generated gcPercent.c and gcPercent.sql.  This header links the database and the RAM 
 * representation of objects. */

#ifndef GCPERCENT_H
#define GCPERCENT_H

struct gcPercent
/* Displays GC percentage in 20Kb blocks for genome */
    {
    struct gcPercent *next;  /* Next in singly linked list. */
    char *chrom;	/* Human chromosome number */
    unsigned chromStart;	/* Start position in genoSeq */
    unsigned chromEnd;	/* End position in genoSeq */
    char *name;	/* Constant string GCpct */
    unsigned gcPpt;	/* GC percentage for 20Kb block */
    };

void gcPercentStaticLoad(char **row, struct gcPercent *ret);
/* Load a row from gcPercent table into ret.  The contents of ret will
 * be replaced at the next call to this function. */

struct gcPercent *gcPercentLoad(char **row);
/* Load a gcPercent from row fetched with select * from gcPercent
 * from database.  Dispose of this with gcPercentFree(). */

struct gcPercent *gcPercentCommaIn(char **pS, struct gcPercent *ret);
/* Create a gcPercent out of a comma separated string. 
 * This will fill in ret if non-null, otherwise will
 * return a new gcPercent */

void gcPercentFree(struct gcPercent **pEl);
/* Free a single dynamically allocated gcPercent such as created
 * with gcPercentLoad(). */

void gcPercentFreeList(struct gcPercent **pList);
/* Free a list of dynamically allocated gcPercent's */

void gcPercentOutput(struct gcPercent *el, FILE *f, char sep, char lastSep);
/* Print out gcPercent.  Separate fields with sep. Follow last field with lastSep. */

#define gcPercentTabOut(el,f) gcPercentOutput(el,f,'\t','\n');
/* Print out gcPercent as a line in a tab-separated file. */

#define gcPercentCommaOut(el,f) gcPercentOutput(el,f,',',',');
/* Print out gcPercent as a comma separated list including final comma. */

#endif /* GCPERCENT_H */

