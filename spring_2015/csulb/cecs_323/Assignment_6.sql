CREATE TABLE Majors
(
	m_code VARCHAR(4) NOT NULL,
	m_name VARCHAR(30) NOT NULL,
	m_department VARCHAR(50),
	m_requiredUnits INT,
	CONSTRAINT majors_pk PRIMARY KEY(m_code)
);

CREATE TABLE Students
(
    s_id	INT,
	 s_fname VARCHAR(20) NOT NULL,
    s_lname VARCHAR(20) NOT NULL,
    s_phone VARCHAR(12) NOT NULL,
    s_address VARCHAR(70) NOT NULL,
    s_city VARCHAR(20) NOT NULL,
    s_state VARCHAR(2) NOT NULL,
    s_zip VARCHAR(5) NOT NULL,
    CONSTRAINT students_pk PRIMARY KEY(s_id)
);


CREATE TABLE MajorsChosen
(
	mc_s_id INT,
	mc_m_code VARCHAR(4),
	CONSTRAINT majorChosen_pk PRIMARY KEY(mc_s_id, mc_m_code),
	CONSTRAINT majorChosen_students_fk FOREIGN KEY (mc_s_id) REFERENCES Students(s_id),
	CONSTRAINT majorChosen_major_fk FOREIGN KEY(mc_m_code) REFERENCES Majors(m_code)
);

CREATE TABLE Accounts
(
	a_s_id INT NOT NULL,
	a_email VARCHAR(50),
	a_accountURL VARCHAR(50),
	a_password   VARCHAR(20),
	CONSTRAINT accounts_pk PRIMARY KEY(a_s_id),
	CONSTRAINT accounts_student_fk FOREIGN KEY (a_s_id) REFERENCES Students(s_id)
);

INSERT INTO Majors VALUES ('CS01', 'Computer Science', 'Computer Science and Computer Engineering', 120);
INSERT INTO Majors VALUES ('CE01', 'Computer Engineering', 'Computer Science and Computer Engineering', 132);
INSERT INTO Majors VALUES ('PH01', 'Physics', 'Physics and Astronomy', 120);
INSERT INTO Majors VALUES ('EE01', 'Electrical Engineering', 'Electrical Engineering', 139);
INSERT INTO Majors VALUES ('CH01', 'Chemical Engineering', 'Chemical Engineering', 120);

INSERT INTO Students VALUES (1111, 'Fred', 'Costner', '714-222-1111', '111 disney street', 'Long Beach', 'CA', '12345');
INSERT INTO Students VALUES (1112, 'Helen', 'Voight', '714-222-1112', '770 Bydgoszcz Avenue', 'Long Beach', 'CA', '82312');
INSERT INTO Students VALUES (1115, 'Lucille', 'Tracy', '714-222-1115', '1866 al-Qatif Avenue', 'El Monte', 'CA', '89420');
INSERT INTO Students VALUES (1116, 'Kirsten', 'Paltrow', '714-222-1116', '1135 Izumisano Parkway', 'Fontana', 'CA', '48150');
INSERT INTO Students VALUES (1117, 'Elvis', 'Marx', '714-222-1117', '1895 Zhezqazghan Drive', 'Garden Grove', 'CA', '36693');
INSERT INTO Students VALUES (1114, 'bob', 'fawcett', '714-222-1114', '1866 al-Qatif Avenue', 'Long Beach', 'CA', '82312');
INSERT INTO Students VALUES (1118, 'Sandra', 'Kilmer', '714-222-1118', '793 Cam Ranh Avenue', 'Lancaster', 'CA', '87057');
INSERT INTO Students VALUES (1119, 'Cameron', 'Streep', '714-222-1119', '920 Kumbakonam Loop', 'Salinas', 'CA', '75090');
INSERT INTO Students VALUES (1120, 'Kevin', 'Bloom', '714-222-1110', '1121 Loja Avenue', 'San Bernardino', 'CA', '17886');
INSERT INTO Students VALUES (1121, 'Rip', 'Crawford', '714-222-1121', '111 Walnut street', 'Citrus Heights', 'CA', '16266');
INSERT INTO Students VALUES (1122, 'Julia', 'Mcqueen', '714-222-1122', '121 Culver street', 'Irvine', 'CA', '92612');
INSERT INTO Students VALUES (1113, 'Dan', 'Torn', '714-222-1113', '533 al-Ayn Boulevard', 'Long Beach', 'CA', '12345');
INSERT INTO Students VALUES (1123, 'Woody', 'Hoffman', '714-222-1123', '235 Beach Aveue', 'Culver', 'CA', '92312');
INSERT INTO Students VALUES (1124, 'Alec', 'Wayne', '714-222-1124', '4566 Barranca', 'Culver', 'CA', '92312');
INSERT INTO Students VALUES (1125, 'Sandra', 'obieski', '714-222-1125', '3321 Wilson street', 'Long Beach', 'CA', '12345');

INSERT INTO MajorsChosen VALUES (1111, 'CS01');
INSERT INTO MajorsChosen VALUES (1111, 'CE01');
INSERT INTO MajorsChosen VALUES (1112, 'CE01');
INSERT INTO MajorsChosen VALUES (1113, 'CE01');
INSERT INTO MajorsChosen VALUES (1114, 'PH01');
INSERT INTO MajorsChosen VALUES (1114, 'CS01');
INSERT INTO MajorsChosen VALUES (1115, 'PH01');
INSERT INTO MajorsChosen VALUES (1116, 'CE01');
INSERT INTO MajorsChosen VALUES (1117, 'CE01');
INSERT INTO MajorsChosen VALUES (1117, 'CS01');
INSERT INTO MajorsChosen VALUES (1118, 'CE01');
INSERT INTO MajorsChosen VALUES (1113, 'PH01');


INSERT INTO Accounts VALUES (1111, 'fred.costner@csulb.net', 'http://csulb.edu/~fredcostner', 'fred001');
INSERT INTO Accounts VALUES (1112, 'helen.voight@csulb.net', 'http://csulb.edu/~helenvoight', 'helen001');
INSERT INTO Accounts VALUES (1115, 'lucille.costner@csulb.net', 'http://csulb.edu/~lucillecostner', 'lucille001');
INSERT INTO Accounts VALUES (1116, 'kirsten.paltrow@csulb.net', 'http://csulb.edu/~kirstenpaltrow', 'kirsten001');
INSERT INTO Accounts VALUES (1117, 'elvis.marx@csulb.net', 'http://csulb.edu/~elvismarx', 'elvis001');
INSERT INTO Accounts VALUES (1114, 'bob.fawcett@csulb.net', 'http://csulb.edu/~bobfawcett', 'bob001');
INSERT INTO Accounts VALUES (1118, 'sandra.kilmer@csulb.net', 'http://csulb.edu/~sandrakilmer', 'sandra001');
INSERT INTO Accounts VALUES (1119, 'cameron.streep@csulb.net', 'http://csulb.edu/~cameronstreep', 'cameron001');
INSERT INTO Accounts VALUES (1120, 'kevin.bloom@csulb.net', 'http://csulb.edu/~kevinbloom', 'kevin001');
INSERT INTO Accounts VALUES (1121, 'rip.crawford@csulb.net', 'http://csulb.edu/~ripcrawford', 'rip001');
INSERT INTO Accounts VALUES (1122, 'julia.mcqueen@csulb.net', 'http://csulb.edu/~juliamcqueen', 'julia001');


