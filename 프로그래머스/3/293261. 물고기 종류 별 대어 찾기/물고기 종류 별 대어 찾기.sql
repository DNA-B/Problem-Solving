SELECT
    ID,
    FISH_NAME,
    LENGTH
FROM
    FISH_INFO
NATURAL JOIN
    FISH_NAME_INFO
WHERE
    (FISH_TYPE, LENGTH) IN (
        SELECT
            FISH_TYPE,
            MAX(LENGTH)
        FROM
            FISH_INFO
        GROUP BY
            FISH_TYPE);