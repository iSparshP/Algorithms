# Write your MySQL query statement below

SELECT contest_id, Round(
    count(distinct user_id)*100/(
        select
        count(user_id) from Users
    ),2
) AS percentage
FROM Register
GROUP BY contest_id
ORDER BY percentage desc, contest_id;

# percent of the users registed in each contest
# rounded to two decimals
# descending order by percentage
# if tie order by contest_id in ascending order