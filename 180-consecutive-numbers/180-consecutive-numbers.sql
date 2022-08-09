/*SELECT DISTINCT l1.Num  as ConsecutiveNums
FROM Logs l1, Logs l2, Logs l3  
WHERE l1.Id + 1 = l2.Id AND l2.Id + 1 = l3.Id AND l1.Num = l2.Num AND l2.Num = l3.Num */

select
    distinct num as ConsecutiveNums 
from 
(
    select 
        num, 
        id - cast(row_number() over (order by num, id) as SIGNED) as rk 
    from 
        logs
) diff_grp
group by 
    num,rk
having 
    count(*) >= 3
