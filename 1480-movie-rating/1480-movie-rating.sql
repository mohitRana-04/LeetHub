# Write your MySQL query statement below
(
select u.name as results
from MovieRating mr
left join Users u 
using(user_id)
group by mr.user_id
order by count(*) desc, u.name
limit 1
)
union all
(
select m.title as results
from MovieRating mr2
left join Movies m 
using(movie_id)
where year(mr2.created_at) = 2020 and month(mr2.created_at) = 2
group by mr2.movie_id
order by avg(mr2.rating) desc, m.title 
limit 1
)