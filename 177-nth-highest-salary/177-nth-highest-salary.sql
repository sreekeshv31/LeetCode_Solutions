CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
  RETURN (
      # Write your MySQL query statement below.
      select max(e1.salary) from employee e1 where n-1 =
      (
          select count(distinct(e2.salary)) from employee e2 where e2.salary>e1.salary
      )
      
  );
END