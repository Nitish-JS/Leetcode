/* Write your PL/SQL query statement below */
Update salary SET sex = CASE 
    when sex='f' then 'm'
    else 'f'
    End;