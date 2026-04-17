# Write your MySQL query statement below
SELECT
    contest_id,
    round(count(distinct user_id) * 100 /(select count(user_id) from Users) ,2) as percentage
FROM Register as r
GROUP BY contest_id
ORDER BY percentage DESC, contest_id;
