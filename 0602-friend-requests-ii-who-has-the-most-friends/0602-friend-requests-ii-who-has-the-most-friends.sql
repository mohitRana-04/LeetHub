# Write your MySQL query statement below
with cte as (
select requester_id as id, accepter_id as num
from RequestAccepted as rc1
union
select accepter_id as id, requester_id as num
from RequestAccepted as rc2
)

select id, count(distinct num) as num
from cte
group by id
order by count(distinct num) desc
limit 1;