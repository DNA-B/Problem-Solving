SELECT 
    COUNT(*) as COUNT
FROM 
    ECOLI_DATA
WHERE 
    GENOTYPE & 2 = 0 AND 
    (GENOTYPE & 1 = 1 OR GENOTYPE & 4 = 4);
    
    
