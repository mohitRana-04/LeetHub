# Write your MySQL query statement below
with cte as (
select visited_on, sum(amount) as amo
from customer
group by visited_on
),
cte2 as(
select visited_on, sum(amo) over(order by visited_on rows between 6 preceding and current row ) as amount,
round(avg(amo) over(order by visited_on rows between 6 preceding and current row), 2) as avg
from cte
)

select visited_on, amount, avg as average_amount
from cte2 
where visited_on >=(
select visited_on
from cte2 
order by visited_on 
limit 1)+6; 
