/* Write your PL/SQL query statement below */
select firstname,lastname,city,state from person left join address on person.personID=address.personID;