/*
 * Joseph Okonoboh
 * Problem a.
 */
SELECT DISTINCT fName, lName, c.street, c.city, c.state, c.zipcode
FROM customers As c
INNER JOIN loans
ON c.id = loans.owner_id
INNER JOIN branches
ON loans.branch_id = branches.id
WHERE branches.state = 'CA'
UNION
SELECT DISTINCT fName, lName, c.street, c.city, c.state, c.zipcode
FROM customers As c
INNER JOIN depositors
ON c.id = depositors.cid
INNER JOIN accounts
ON depositors.account_number = accounts.account_number
INNER JOIN branches
ON accounts.branch_id = branches.id
WHERE branches.state = 'CA';

/*
 * Problem b.
 */
SELECT fName, lName, street, city, state, zipcode
FROM customers
INNER JOIN loans
ON customers.id = loans.owner_id
WHERE customers.id NOT IN
(SELECT customers.id
FROM customers
INNER JOIN depositors
ON customers.id = depositors.cid);


SELECT c.id, IFNULL(SUM(loan_number), 0)
FROM customers AS c
LEFT JOIN loans
ON c.id = loans.owner_id
GROUP BY c.id;

SELECT c.id, IFNULL(SUM(loan_number), 0)
FROM customers AS c
LEFT JOIN loans
ON c.id = loans.owner_id
GROUP BY c.id


 