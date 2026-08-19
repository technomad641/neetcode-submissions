const DOC_ID = 'REPLACE_WITH_GOOGLE_DOC_ID';

/**
 * Google Apps Script endpoint for the continuous-sync phase.
 * Deploy as a Web app and grant access only to the intended account/users.
 * The endpoint reads the Google Doc and returns every NeetCode URL it finds.
 */
function doGet() {
  const doc = DocumentApp.openById(DOC_ID);
  const text = doc.getBody().getText();
  const matches = text.match(/https:\/\/neetcode\.io\/problems\/[^\s<>\]\)]+/g) || [];
  const urls = [...new Set(matches.map(cleanUrl))];
  return ContentService
    .createTextOutput(JSON.stringify({updatedAt:new Date().toISOString(), urls}))
    .setMimeType(ContentService.MimeType.JSON);
}

function cleanUrl(url) {
  return url.replace(/[.,;]+$/, '');
}

/**
 * Optional scheduled change detector. Apps Script can run this on a time trigger.
 * It stores the last document revision timestamp so downstream systems can poll
 * or react only when the source document changed.
 */
function checkForChange() {
  const props = PropertiesService.getScriptProperties();
  const doc = DocumentApp.openById(DOC_ID);
  const stamp = String(doc.getLastUpdated().getTime());
  const oldStamp = props.getProperty('LAST_UPDATED');
  if (stamp !== oldStamp) {
    props.setProperty('LAST_UPDATED', stamp);
    // Add a webhook/email/push integration here if desired.
  }
}
