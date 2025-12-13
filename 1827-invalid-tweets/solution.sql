# Write your MySQL query statement below
WITH answer AS(
    SELECT
        tweet_id
    FROM Tweets
    WHERE length(content)>15
)
SELECT
    tweet_id 
FROM answer;
