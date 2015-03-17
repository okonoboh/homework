/** Problem 1 **/
SELECT m_name AS major_name, COUNT(mc_s_id) AS num
FROM Majors LEFT JOIN MajorsChosen
ON Majors.m_code = MajorsChosen.mc_m_code
GROUP BY m_name

/** Problem 2 **/
SELECT COUNT(s_id) AS num
FROM Students LEFT JOIN Accounts
ON Students.s_id = Accounts.a_s_id
WHERE a_email IS NULL AND Students.s_city = 'Long Beach'
                      AND Students.s_state = 'CA'

/** Problem 3 **/
SELECT s_fname AS first_name, s_lname AS last_name, num_majors, max_units
FROM
      (SELECT s_id, s_fname, s_lname, IFNULL(MAX(m_requiredUnits), 0) AS max_units
       FROM Students LEFT JOIN MajorsChosen
       ON Students.s_id = MajorsChosen.mc_s_id
       LEFT JOIN Majors
       ON MajorsChosen.mc_m_code = Majors.m_code
       WHERE s_state = 'CA'
       GROUP BY s_id) AS l
INNER JOIN
      (SELECT s_id, COUNT(mc_m_code) AS num_majors
       FROM Students LEFT JOIN MajorsChosen
       ON Students.s_id = MajorsChosen.mc_s_id
       GROUP BY s_id) AS r
ON l.s_id = r.s_id

/** Problem 4 **/
SELECT m_name AS major_name, s_city AS city, COUNT(s_city) AS num_city
FROM Majors INNER JOIN MajorsChosen
ON Majors.m_code = MajorsChosen.mc_m_code
INNER JOIN Students
ON MajorsChosen.mc_s_id = Students.s_id
GROUP BY m_name, s_city
HAVING num_city > 1

/** Problem 5 **/
SELECT s_fname AS first_name, s_lname AS last_name, s_phone AS phone_num
FROM
      (SELECT s_id, s_fname, s_lname, s_phone, COUNT(mc_m_code) AS num_majors
       FROM Students INNER JOIN MajorsChosen
       ON Students.s_id = MajorsChosen.mc_s_id
       GROUP BY s_id
       HAVING num_majors > 1) AS l
LEFT JOIN
       Accounts
ON l.s_id = Accounts.a_s_id
WHERE a_email IS NULL
