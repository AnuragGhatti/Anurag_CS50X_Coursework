-- Keep a log of any SQL queries you execute as you solve the mystery.
SELECT * FROM crime_scene_reports
WHERE year = 2021 AND month = 7 AND day = 28 AND street = "Chamberlin Street";

SELECT name, transcript FROM interviews
WHERE year = 2021 AND month = 7 AND day = 28 AND transcript LIKE "%bakery%";

SELECT * FROM atm_transactions
WHERE atm_location = "Leggett Street" AND year = 2021 AND month = 7 AND day = 28 AND transaction_type = "withdraw";

SELECT people.name, bank_accounts.account_number FROM people
JOIN bank_accounts ON people.id = bank_accounts.person_id
WHERE account_number IN (28500762, 28296815, 76054385, 49610011, 16153065, 25506511);

SELECT * FROM bakery_security_logs
WHERE year = 2021 AND month = 7 AND day = 28
AND hour = 10 AND minute BETWEEN 15 AND 25;

SELECT name, license_plate FROM people
WHERE license_plate IN ('5P2BI95','94KL13X','322W7JE','0NTHK55','1106N58','6P58WS2','4328GD8','G412CB7');

SELECT * FROM phone_calls
WHERE year = 2021 AND month = 7 AND day = 28 AND duration < 60;

SELECT p1.name AS caller, p2.name AS receiver, duration FROM phone_calls
JOIN people p1 ON phone_calls.caller = p1.phone_number
JOIN people p2 ON phone_calls.receiver = p2.phone_number
WHERE year = 2021 AND month = 7 AND day = 28 AND duration < 60;

SELECT * FROM flights
JOIN airports ON flights.origin_airport_id = airports.id
WHERE airports.city = "Fiftyville" AND year = 2021 AND month = 7 AND day = 29
ORDER BY hour, minute LIMIT 1;

SELECT people.name FROM passengers
JOIN people ON passengers.passport_number = people.passport_number
WHERE flight_id = 36;
