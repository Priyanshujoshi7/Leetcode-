# Write your MySQL query statement below
WITH ANS AS(
    SELECT
        requester_id  as id
    FROM RequestAccepted
UNION ALL

SELECT
    accepter_id as id
FROM RequestAccepted)

SELECT
    id,
    COUNT(*) num 
FROM ANS
GROUP BY 1
ORDER BY 2 DESC
LIMIT 1;
