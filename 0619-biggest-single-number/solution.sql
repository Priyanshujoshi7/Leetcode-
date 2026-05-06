SELECT
    max(num) as num
FROM MyNumbers n
WHERE num IN(
    SELECT
        num
    FROM Mynumbers
    GROUP BY num
    HAVING COUNT(*) =1
)
