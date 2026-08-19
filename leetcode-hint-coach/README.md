# LeetCode Hint Coach 📱

An iPhone-first study app built from the LeetCode/NeetCode list in `Neetcode-Questions.pdf`.

## What is included

- 22 problems extracted from the uploaded PDF.
- One-problem-at-a-time study flow.
- Three progressive hints per problem.
- Solved / review / skip state stored locally on the iPhone.
- Progress dashboard and topic-independent review queue.
- Installable as an iPhone Home Screen web app (PWA).
- Offline app shell via service worker.
- Source links back to the NeetCode problem.

The uploaded source contains a two-column `Problems / Date` table. The first problem has date `7/18`; the remaining listed problems have no date in the PDF. The final page also contains a Stack Overflow link unrelated to the LeetCode list, so it is not included as a problem. fileciteturn8file0L2-L30

## Run on your current iPhone

The app is static HTML/CSS/JavaScript, so it does not require a backend for the core study experience.

1. Open the repository's `leetcode-hint-coach/` folder through a static web host (GitHub Pages is recommended).
2. Open the deployed URL in Safari on the iPhone.
3. Tap **Share → Add to Home Screen**.
4. Launch **LeetCode Hint Coach** from the Home Screen.

For local development, any static HTTP server works, for example:

```bash
python3 -m http.server 8000
```

Then open `http://localhost:8000/leetcode-hint-coach/` on a device reachable from the same network.

## Google Docs continuous sync

The PDF is a snapshot of the current document. The app deliberately does not embed Google credentials or attempt to scrape a private Google Doc from the browser.

The next production step is to connect the Google Docs API through a small authenticated sync service. That service should:

1. Watch the configured Google Doc for changes.
2. Fetch the document when it changes.
3. Extract NeetCode URLs.
4. Diff them against `questions.json`.
5. Add newly discovered questions and preserve local progress by stable URL.
6. Generate/store hints server-side if desired.

This keeps Google OAuth credentials out of the iPhone app.
