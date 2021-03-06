# knownIsoforms.sql was originally generated by the autoSql program, which also 
# generated knownIsoforms.c and knownIsoforms.h.  This creates the database representation of
# an object which can be loaded and saved from RAM in a fairly 
# automatic way.

#Links together various transcripts of a gene into a cluster
CREATE TABLE knownIsoforms (
    clusterId int not null,	# Unique id for transcript cluster (aka gene)
    transcript varchar(255) not null,	# Corresponds to name in knownGene table, transcript in knownCanonical
              #Indices
    UNIQUE KEY `transcript` (`transcript`),
    INDEX(clusterId)
);
