# fosEndPairs.sql was originally generated by the autoSql program, which also 
# generated fosEndPairs.c and fosEndPairs.h.  This creates the database representation of
# an object which can be loaded and saved from RAM in a fairly 
# automatic way.

#Positions of end pairs for fosmids
CREATE TABLE fosEndPairs (
    bin smallint not null,	# Bin number for browser speedup
    chrom varchar(255) not null,	# Human chromosome
    chromStart int unsigned not null,	# Start position of fosmid in chromosome
    chromEnd int unsigned not null,	# End position of fosmid in chromosome
    name varchar(255) not null,	# Name of fosmid
    score int unsigned not null,	# Score = 1000/(# of times fosmid appears in assembly)
    strand char(1) not null,	# Value should be + or -
    pslTable varchar(255) not null,	# Table which contains corresponding PSL records for linked features
    lfCount int unsigned not null,	# Number of linked features in the series
    lfStarts longblob not null,	# Comma separated list of start positions of each linked feature in genomic
    lfSizes longblob not null,	# Comma separated list of sizes of each linked feature in genomic
    lfNames longblob not null,	# Comma separated list of names of linked features
              #Indices
    INDEX(chrom(8), bin),
    INDEX(chrom(8),chromStart),
    INDEX(name(16))
);

